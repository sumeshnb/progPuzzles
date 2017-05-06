template<typename T>
struct Link{
  Link *prev;
  Link *next;
  T val;
};

template<typename T>
class List{
  Link<T> *head;

public:
  List():head{7}{};
};

/*int main(){
  List<char> l;
}*/
