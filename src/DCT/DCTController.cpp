#include "DCTController.h"

string DCTController::input = "Trab2Flavio/input.dct";
string DCTController::output = "Trab2Flavio/output.dct";

float DCTController::xSpace = 150;
float DCTController::ySpace = 0;
float DCTController::graphH = 100;
float DCTController::graphW = 300;
float DCTController::graphGap = 30;


DCTController::DCTController(){
    set_graphs();
    DCT_from_file();
}

void DCTController::set_graphs(){
    vector<double> zeroV = {0};
    //input
    float x1 = graphGap + xSpace, x2 = graphGap + graphW + xSpace;
    float y1 = graphGap + ySpace, y2 = graphGap + graphH + ySpace;
    Graph *Ginput = new Graph("Input", new Vector2(x1, y1), new Vector2(x2, y2),
                             new PointSet(zeroV));
    Ginput->set_border_color(1,0,0);

    //DCT
    x1 += graphGap + graphW;
    x2 += graphGap + graphW;
    Graph *Gdct = new Graph("DCT", new Vector2(x1, y1), new Vector2(x2, y2),
                             new PointSet(zeroV));
    Gdct->set_border_color(0,0,1);

    //QUANT
    x1 -= graphGap + graphW;
    x2 -= graphGap + graphW;
    y1 += graphGap + graphH;
    y2 += graphGap + graphH;
    Graph *Gquant = new Graph("DCT quantizada", new Vector2(x1, y1), new Vector2(x2, y2),
                             new PointSet(zeroV));
    Gquant->set_border_color(0,0.5,0);

    //DEQUANT
    x1 += graphGap + graphW;
    x2 += graphGap + graphW;
    Graph *Gdequant = new Graph("DCT desquantizada", new Vector2(x1, y1), new Vector2(x2, y2),
                                 new PointSet(zeroV));
    Gdequant->set_border_color(0.5,0,0.5);

    //IDCT
    x1 -= graphGap + graphW;
    x2 -= graphGap + graphW;
    y1 += graphGap + graphH;
    y2 += graphGap + graphH;
    Graph *Gidct = new Graph("IDCT", new Vector2(x1, y1), new Vector2(x2, y2),
                             new PointSet(zeroV));
    Gidct->set_border_color(0,0.5,0.5);

    //DIFF
    x1 += graphGap + graphW;
    x2 += graphGap + graphW;
    Graph *Gdiff = new Graph("Diferenca", new Vector2(x1, y1), new Vector2(x2, y2),
                             new PointSet(zeroV));
    Gdiff->set_border_color(0.6,0,0.2);


    original = Ginput;
    dct = Gdct;
    quant = Gquant;
    dequant = Gdequant;
    idct = Gidct;
    diff = Gdiff;
}

void DCTController::att_graphs(vector<double> inp){
    vector<double> Vdct = CosineTransformer::DCT(inp);
    vector<double> Vquant = CosineTransformer::QUANT(Vdct);
    vector<double> Vdequant = CosineTransformer::DEQUANT(Vquant);
    vector<double> Vidct = CosineTransformer::IDCT(Vdequant);
    vector<double> Vdiff = CosineTransformer::DIFF(inp, Vidct);


    original->set_points(new PointSet(inp));
    dct->set_points(new PointSet(Vdct));
    quant->set_points(new PointSet(Vquant));
    dequant->set_points(new PointSet(Vdequant));
    idct->set_points(new PointSet(Vidct));
    diff->set_points(new PointSet(Vdiff));
    
}


void DCTController::DCT_from_rand(int n){
    att_graphs( CosineTransformer::RAND(n) );
}

void DCTController::DCT_from_sin(int n){
    att_graphs( CosineTransformer::SIN(n) );
}

void DCTController::DCT_from_file(){
    vector<char> inp = FileHandler::load(input);
    if(inp.size() <= 0){
        DCT_from_rand(32);
    } else{
        auto input = char_to_double(inp);
        att_graphs(input);
    }

}

void DCTController::save_output(){
    DCT_from_file();
    vector<double> *out = new vector<double>(*(idct->points->points));

    FileHandler::save(double_to_char(*out), output);
}

void DCTController::load_from_actual(){
    vector<double> *out = new vector<double>(*(original->points->points));

    FileHandler::save(double_to_char(*out), input);
}


vector<char> DCTController::double_to_char(vector<double> ds){
    vector<char> cs(ds.size() + 4);
    int size = ds.size();
    memcpy(&cs[0], &size, 4);

    for(int i = 0; i < size; i++){
        char c = (char) ds.at(i);
        cs.at(i+4) = c;
    }

    return cs;
}

vector<double> DCTController::char_to_double(vector<char> cs){
    vector<double> ds;
    int size;
    memcpy(&size, &cs[0], 4);

    for(int i = 4; i < size+4; i++){
        double d = (double) cs.at(i);
        ds.push_back(d);
    }
    return ds;
}

void DCTController::set_quantization_factor(double q){
    CosineTransformer::set_quantization_factor(q);
    att_graphs(*(original->points->points));
}

void DCTController::draw(){
    GraphDrawer::draw(original);
    GraphDrawer::draw(dct);
    GraphDrawer::draw(quant);
    GraphDrawer::draw(dequant);
    GraphDrawer::draw(idct);
    GraphDrawer::draw(diff);
}

double DCTController::get_quantization_factor(){
    return CosineTransformer::get_quantization_factor();
}
