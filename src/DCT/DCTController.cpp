#include "DCTController.h"

string DCTController::input = "input.dct";
string DCTController::output = "output.dct";

float DCTController::xSpace = 150;
float DCTController::ySpace = 0;
float DCTController::graphH = 100;
float DCTController::graphW = 300;
float DCTController::graphGap = 30;


DCTController::DCTController(){
    DCT_from_file();
}

DCTController::~DCTController(){
    delete this->gm;
}

void DCTController::init_graphs(vector<double> input){
    if(this->gm != nullptr) delete this->gm;

    GraphManager *gm = new GraphManager();

    vector<double> dct = CosineTransformer::DCT(input);
    vector<double> quant = CosineTransformer::QUANT(dct);
    vector<double> dequant = CosineTransformer::DEQUANT(quant);
    vector<double> idct = CosineTransformer::IDCT(dequant);
    vector<double> diff = CosineTransformer::DIFF(input, idct);

    this->original = input;
    this->compressed = idct;

    //input
    float x1 = graphGap + xSpace, x2 = graphGap + graphW + xSpace;
    float y1 = graphGap + ySpace, y2 = graphGap + graphH + ySpace;
    Graph *Ginput = new Graph("Input", new Vector2(x1, y1), new Vector2(x2, y2),
                             new PointSet(input));
    Ginput->points->print();

    //DCT
    x1 += graphGap + graphW;
    x2 += graphGap + graphW;
    Graph *Gdct = new Graph("DCT", new Vector2(x1, y1), new Vector2(x2, y2),
                             new PointSet(dct));
    Gdct->points->print();

    //QUANT
    x1 -= graphGap + graphW;
    x2 -= graphGap + graphW;
    y1 += graphGap + graphH;
    y2 += graphGap + graphH;
    Graph *Gquant = new Graph("DCT quantizada", new Vector2(x1, y1), new Vector2(x2, y2),
                             new PointSet(quant));
    Gquant->points->print();

    //DEQUANT
    x1 += graphGap + graphW;
    x2 += graphGap + graphW;
    Graph *Gdequant = new Graph("DCT desquantizada", new Vector2(x1, y1), new Vector2(x2, y2),
                                 new PointSet(dequant));
    Gdequant->points->print();

    //IDCT
    x1 -= graphGap + graphW;
    x2 -= graphGap + graphW;
    y1 += graphGap + graphH;
    y2 += graphGap + graphH;
    Graph *Gidct = new Graph("IDCT", new Vector2(x1, y1), new Vector2(x2, y2),
                             new PointSet(idct));
    Gidct->points->print();

    //DIFF
    x1 += graphGap + graphW;
    x2 += graphGap + graphW;
    Graph *Gdiff = new Graph("Diferenca", new Vector2(x1, y1), new Vector2(x2, y2),
                             new PointSet(diff));
    Gdiff->points->print();

    gm->add_graph(Ginput);
    gm->add_graph(Gdct);
    gm->add_graph(Gquant);
    gm->add_graph(Gdequant);
    gm->add_graph(Gidct);
    gm->add_graph(Gdiff);

    this->gm = gm;
}


void DCTController::DCT_from_rand(int n){
    init_graphs( CosineTransformer::RAND(n) );
}

void DCTController::DCT_from_file(){
    vector<char> inp = FileHandler::load(input);
    if(inp.size() <= 0) return;

    init_graphs( char_to_double(inp) );
}

void DCTController::save_output(){
    DCT_from_file();
    FileHandler::save(double_to_char(compressed), output);
}

vector<char> DCTController::double_to_char(vector<double> ds){
    vector<char> cs;
    for(auto d : ds){
        char c = (char) d;
        cs.push_back(c);
    }
    return cs;
}

vector<double> DCTController::char_to_double(vector<char> cs){
    vector<double> ds;
    for(auto c : cs){
        double d = (double) c;
        ds.push_back(d);
    }
    return ds;
}

void DCTController::set_quantization_factor(double q){
    CosineTransformer::set_quantization_factor(q);
    init_graphs(original);
}

void DCTController::draw(){
    gm->draw();
}

double DCTController::get_quantization_factor(){
    return CosineTransformer::get_quantization_factor();
}
