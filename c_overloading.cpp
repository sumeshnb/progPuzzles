extern "C" {
	int f(int);
	int f(double);
};
int f(int a){
	a++;
}
int f(double d){
	d+=1;
}
