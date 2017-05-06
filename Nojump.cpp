class X{
    public:
        X();
};

X::X(){}

int main(){

    int i=10;
    if(i<10)
        goto jump1;
    X x1;
jump1:
    switch(i){
        case 1:
            X x2;
            break;
        case 2:
            X x3;
            break;
    }
}
