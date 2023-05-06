#include "DCTController.h"

string DCTController::input = "input.dct";
string DCTController::output = "output.dct";

DCTController::DCTController(){
    DCT_from_file();
}

DCTController::~DCTController(){
    delete this->gm;
}

void DCTController::init_graphs(vector<double> input){
    if(this->gm != nullptr) delete this->gm;

    GraphManager *gm = new GraphManager();

    int graphH = 100;
    int graphW = 400;
    int graphGap = 50;

    vector<double> dct = CosineTransformer::DCT(input);
    vector<double> quant = CosineTransformer::QUANT(dct);
    vector<double> dequant = CosineTransformer::DEQUANT(quant);
    vector<double> idct = CosineTransformer::IDCT(dequant);
    vector<double> diff = CosineTransformer::DIFF(input, idct);

    this->original = input;

    //input
    Graph *Ginput = new Graph("Input", new Vector2(graphGap, graphGap), new Vector2(graphGap + graphW, graphGap + graphH),
                             new PointSet(input));
    Ginput->points->print();

    //DCT
    Graph *Gdct = new Graph("DCT", new Vector2(graphGap*2 + graphW, graphGap), new Vector2(graphGap*2 + graphW*2, graphGap + graphH),
                             new PointSet(dct));
    Gdct->points->print();

    //QUANT
    Graph *Gquant = new Graph("DCT quantizada", new Vector2(graphGap, graphGap*2 + graphH), new Vector2(graphGap + graphW, graphGap*2 + graphH*2),
                             new PointSet(quant));
    Gquant->points->print();

    //DEQUANT
    Graph *Gdequant = new Graph("DCT desquantizada", new Vector2(graphGap*2 + graphW, graphGap*2 + graphH), new Vector2(graphGap*2 + graphW*2, graphGap*2 + graphH*2),
                                 new PointSet(dequant));
    Gdequant->points->print();

    //IDCT
    Graph *Gidct = new Graph("IDCT", new Vector2(graphGap, graphGap*3 + graphH*2), new Vector2(graphGap + graphW, graphGap*3 + graphH*3),
                             new PointSet(idct));
    Gidct->points->print();

    //DIFF
    Graph *Gdiff = new Graph("Diferenca", new Vector2(graphGap*2 + graphW, graphGap*3 + graphH*2), new Vector2(graphGap*2 + graphW*2, graphGap*3 + graphH*3),
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

void DCTController::DCT_from_file(){
    init_graphs( char_to_double(FileHandler::load(input)) );

}

void DCTController::DCT_from_rand(int n){
    init_graphs( CosineTransformer::RAND(n) );
}

void DCTController::save_output(vector<double> vec){
    FileHandler::save(double_to_char(vec), output);
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
