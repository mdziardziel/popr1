#include<iostream>
#include<list>
#include<stdexcept>
#include<cstddef>
#include<map>
#include<cstdlib>
#include<vector>
#include<fstream>
#include<string>

using namespace std;
/*
Klasy od A-J mają podobne elementy. Pole name to nazwa obiektu;
pole z to pole protected, które jest dziedziczone przez klasy potomne;
pole x to parametr klasy;
statyczna zmienna wezel odpowiada za przechowywanie nazwy aktualnego węzła;
odpowiadają im metody get i set które odpowienio pobierają i nadają im wartości
Konstruktowy są uzupełnione tylko przy klasach których można stworzyć obiekty, nadaje się w nich ich nazwy;
*/
class A{
protected:
  string name;
  string a;
private:
  static string wezel;
  string x;
public:
  A(){}
  ~A(){}
  static string getWezel(){
    return wezel;
  }
  static void setWezel(string wezel){
    A::wezel = wezel;;
  }
  virtual void setName(string name){
    this -> name = name;
  }
  virtual string getName(){
    return name;
  }
  void setX(string x){
    this -> x = x;
  }
  string getX(){
    return x;
  }
  virtual void seta(string a){
    this -> a = a;
  }
  virtual string geta(){
    return a;
  }
};

class B : virtual public A{
private:
  string x;
protected:
  string b;
protected:
  B(){}
  ~B(){}
public:
  virtual void setb(string a){
    b = a;
  }
  virtual string getb(){
    return b;
  }
};

class C : virtual public A{
private:
  string x;
protected:
  string c;
protected:
  C(){}
  ~C(){}
public:
  virtual void setc(string a){
    c = a;
  }
  virtual string getc(){
    return c;
  }
};

class D : virtual public A{
private:
  string x;
protected:
  string d;
protected:
  D(){}
  ~D(){}
public:
  virtual void setd(string a){
    d = a;
  }
  virtual string getd(){
    return d;
  }
};

class E : public C{
private:
  string x;
protected:
  string e;
public:
  E(string name){
      this -> A::name = name;
  }
  ~E(){}
  static map<string, E*> objects;
  virtual void sete(string a){
    e = a;
  }
  virtual string gete(){
    return e;
  }
};

class F : public C{
private:
  string x;
protected:
  string f;
public:
  F(string name){
      this -> A::name = name;
  }
  ~F(){}
  static map<string, F*> objects;
  virtual void setf(string a){
    f = a;
  }
  virtual string getf(){
    return f;
  }
};

class G : public D{
private:
  string x;
protected:
  string g;
protected:
  G(){}
  ~G(){}
public:
  virtual void setg(string a){
    g = a;
  }
  virtual string getg(){
    return g;
  }
};

class H : public D{
private:
  string x;
protected:
  string h;
public:
  H(string name){
      this -> A::name = name;
  }
  ~H(){}
  static map<string, H*> objects;
  virtual void seth(string a){
    h = a;
  }
  virtual string geth(){
    return h;
  }
};

class I : public B,  public C{
private:
  string x;
protected:
  string i;
public:
  I(string name){
      this -> B::name = name;
  }
  ~I(){}
  static map<string, I*> objects;
  virtual void seti(string a){
    i = a;
  }
  virtual string geti(){
    return i;
  }
};

class J : public B, public G{
private:
  string x;
protected:
  string j;
public:
  J(string name){
    this -> B::name = name;
  }
  ~J(){}
  static map<string, J*> objects;
  virtual void setj(string a){
    j = a;
  }
  virtual string getj(){
    return j;
  }
};


map<string, E*> E::objects;//inicjowanie statycznych map
map<string, F*> F::objects;
map<string, H*> H::objects;
map<string, I*> I::objects;
map<string, J*> J::objects;
string A::wezel;

class Polecenie{
/*
Ta klasa obpowiada za pobieranie i przetwarzanie komend z terminala;
W konstruktorze pobieramy polecenie z terminala
*/
private:
    string polecenie, komenda, parametr, parametr1, parametr2;
    string tab[20];
public:
  Polecenie(){
    setPolecenie();
    split();
  }
  ~Polecenie(){}

  void split(){
    int i = 0, j = 0;
    while(i < polecenie.size()){
      if(polecenie[i] == ' '){
        i++; j++;
      }
      tab[j] += polecenie[i];//zczytywanie litera po literze i dodawanie do stringa aż nie będzie spacji
      i++;
    }
  }

  string getPolecenie(){
    return polecenie;
  }

  string getParametrN(int x){
    return tab[x];
  }

  void setParametrN(string pam, int x){
    tab[x] = pam;
  }

  void setPolecenie(){
    //cin>>polecenie;
    getline(cin,polecenie);
    cout<<endl;
  }
  void setParametr(string parametr){
    tab[1] = parametr;
  }

  string getKomenda(){
    return tab[0];
  }

  string getParametr(){
    return tab[1];
  }

  string getParametr1(){
    return tab[2];
  }

  string getParametr2(){
    return tab[3];
  }
  //akceptuję duże lub małe litery
  void proceed(){
    if(getKomenda() == "EXIT" || getKomenda() == "exit"){
      ex();
    }
    else if(getKomenda() == "CD" || getKomenda() == "cd"){
      cd();
    }
    else if(getKomenda() == "MO" || getKomenda() == "mo"){
      mo();
    }
    else if(getKomenda() == "DO" || getKomenda() == "do"){
      doo();
    }
    else if(getKomenda() == "MDO" || getKomenda() == "mdo"){
      mdo();
    }
    else if(getKomenda() == "DIR" || getKomenda() == "dir"){
      dir();
    }
    else if(getKomenda() == "SHOW" || getKomenda() == "show"){
      show();
    }
    else if(getKomenda() == "SAVE" || getKomenda() == "save"){
      savee();
    }
    else if(getKomenda() == "READ" || getKomenda() == "read"){
      readd();
    }
    else if(getKomenda() == "TREE" || getKomenda() == "tree"){
      tree();
    }
    else if(getKomenda() == "CT" || getKomenda() == "ct"){
      clearTree();
    }
    else cout<<"Nie ma takiej komendy!"<<endl;
  }

private:
//metoda usuwająca wszytskie obiekty
  void clearTree(){
    string wez = A::getWezel(); //pobieramy nazwę węzła
    for(int i = 0; i < 5; i++){
      A::setWezel("E");// nadajemy ity liść
      for(auto& x : E::objects){ // przejeżdzamy się po wszystkich obiektach w mapie i usuwamy
        setParametr(x.first);
        doo();
      }
    }
    for(int i = 0; i < 5; i++){
      A::setWezel("F");// nadajemy ity liść
      for(auto& x : F::objects){ // przejeżdzamy się po wszystkich obiektach w mapie i usuwamy
        setParametr(x.first);
        doo();
      }
    }
    for(int i = 0; i < 5; i++){
      A::setWezel("H");// nadajemy ity liść
      for(auto& x : H::objects){ // przejeżdzamy się po wszystkich obiektach w mapie i usuwamy
        setParametr(x.first);
        doo();
      }
    }
    for(int i = 0; i < 5; i++){
      A::setWezel("I");// nadajemy ity liść
      for(auto& x : I::objects){ // przejeżdzamy się po wszystkich obiektach w mapie i usuwamy
        setParametr(x.first);
        doo();
      }
    }
    for(int i = 0; i < 5; i++){
      A::setWezel("J");// nadajemy ity liść
      for(auto& x : J::objects){ // przejeżdzamy się po wszystkich obiektach w mapie i usuwamy
        setParametr(x.first);
        doo();
      }
    }
    A::setWezel(wez); //przywracamy początkowy węzeł
  }
  void ex(){
    clearTree();// przy wyjściu po Bożemu usuwamy wszystkie obiekty
    exit(0);
  }
//metoda wybierająca węzeł
  void cd(){
    if( 65 <= (int)getParametr()[0] && (int)getParametr()[0] <= 74 ){ // sprawdzamy czy wybrany węzeł zawiera się w posiadanych
      A::setWezel(getParametr()); // zmieniamy węzeł
      cout<<"Zmieniłeś węzeł na "<<A::getWezel()<<endl;
    }
    else cout<<"Nie ma węzła o nazwie: "<<getParametr()<<endl;
  }
//metoda tworząca węzeł
  void mo(){
    if(A::getWezel() == "E"){
      E *actn = new E(getParametrN(1)); //tworzymy nowy obiekt
      E::objects[getParametrN(1)]= actn; // dodajemy do mapy obiektów
      actn -> setX(getParametrN(2)); // nadajemy wartość paramwtrów x i y
      actn -> sete(getParametrN(3));
      actn -> seta(getParametrN(4));
      actn -> setc(getParametrN(5));
      cout<<"Dodałeś obiekt o nazwie "<<actn ->getName()<<" do liścia "<<A::getWezel()<<" o parametrach "<<actn -> getX()<<", "<<actn -> gete()<<", "<<actn -> getc()<<", "<<actn -> geta()<<endl;
    }
    else if(A::getWezel() == "F"){
      F *actn = new F(getParametrN(1));
      F::objects[getParametrN(1)]= actn;
      actn -> setX(getParametrN(2)); // nadajemy wartość paramwtrów x i y
      actn -> setf(getParametrN(3));
      actn -> seta(getParametrN(4));
      actn -> setc(getParametrN(5));
      cout<<"Dodałeś obiekt o nazwie "<<actn ->getName()<<" do liścia "<<A::getWezel()<<" o parametrach "<<actn -> getX()<<", "<<actn -> getf()<<", "<<actn -> getc()<<", "<<actn -> geta()<<endl;
    }
    else if(A::getWezel() == "H"){
      H *actn = new H(getParametrN(1));
      H::objects[getParametrN(1)]= actn;
      actn -> setX(getParametrN(2)); // nadajemy wartość paramwtrów x i y
      actn -> seth(getParametrN(3));
      actn -> seta(getParametrN(4));
      actn -> setd(getParametrN(5));
      cout<<"Dodałeś obiekt o nazwie "<<actn ->getName()<<" do liścia "<<A::getWezel()<<" o parametrach "<<actn -> getX()<<", "<<actn -> geth()<<", "<<actn -> getd()<<", "<<actn -> geta()<<endl;
    }
    else if(A::getWezel() == "I"){
      I *actn = new I(getParametrN(1));
      I::objects[getParametrN(1)]= actn;
      actn -> setX(getParametrN(2)); // nadajemy wartość paramwtrów x i y
      actn -> seti(getParametrN(3));
      actn -> seta(getParametrN(4));
      actn -> setb(getParametrN(5));
      actn -> setc(getParametrN(6));
      cout<<"Dodałeś obiekt o nazwie "<<actn ->getName()<<" do liścia "<<A::getWezel()<<" o parametrach "<<actn -> getX()<<", "<<actn -> geti()<<", "<<actn -> getb()<<", "<<actn -> geta()<<", "<<actn -> getc()<<endl;
    }
    else if(A::getWezel() == "J"){
      J *actn = new J(getParametrN(1));
      J::objects[getParametrN(1)]= actn;
      actn -> setX(getParametrN(2));
      actn -> setj(getParametrN(3));
      actn -> seta(getParametrN(4));
      actn -> setb(getParametrN(5));
      actn -> setg(getParametrN(6));
      actn -> setd(getParametrN(7));
      cout<<"Dodałeś obiekt o nazwie "<<actn ->getName()<<" do liścia "<<A::getWezel()<<" o parametrach "<<actn -> getX()<<", "<<actn -> getj()<<", "<<actn -> getb()<<", "<<actn -> geta()<<", "<<actn -> getg()<<", "<<actn -> getd()<<endl;
    }
    else{
      cout<<"Nie można stworzyć obiektu, nie jesteś w liściu!"<<endl;
    }
  }
//metoda usuwająca obiekt o danej nazwie
  void doo(){
    if(A::getWezel() == "E"){
      if(E::objects.find(getParametr()) != E::objects.end()){ // sprawdzamy czy mamy w węźle obiekt o podanej nazwie
        delete E::objects[getParametr()]; // usuwamy obiekt
        E::objects.erase(E::objects.find(getParametr())); //usuwamy obiekt z mapy
        cout<<"Usunąłeś obiekt o nazwie "<<getParametr()<<" z liścia "<<A::getWezel()<<endl;
      }
      else cout<<"Nie masz obiektu o takiej nazwie w tym węźle!"<<endl;

    }
    else if(A::getWezel() == "F"){
      if(F::objects.find(getParametr())!=F::objects.end()){
        delete F::objects[getParametr()];
        F::objects.erase(F::objects.find(getParametr()));
        cout<<"Usunąłeś obiekt o nazwie "<<getParametr()<<" z liścia "<<A::getWezel()<<endl;
      }
      else cout<<"Nie masz obiektu o takiej nazwie w tym węźle!"<<endl;
    }
    else if(A::getWezel() == "H"){
      if(H::objects.find(getParametr())!=H::objects.end()){
        delete H::objects[getParametr()];
        H::objects.erase(H::objects.find(getParametr()));
        cout<<"Usunąłeś obiekt o nazwie "<<getParametr()<<" z liścia "<<A::getWezel()<<endl;
      }
      else cout<<"Nie masz obiektu o takiej nazwie w tym węźle!"<<endl;
    }
    else if(A::getWezel() == "I"){
      if(I::objects.find(getParametr())!=I::objects.end()){
        delete I::objects[getParametr()];
        I::objects.erase(I::objects.find(getParametr()));
        cout<<"Usunąłeś obiekt o nazwie "<<getParametr()<<" z liścia "<<A::getWezel()<<endl;
      }
      else cout<<"Nie masz obiektu o takiej nazwie w tym węźle!"<<endl;
    }
    else if(A::getWezel() == "J"){
      if(J::objects.find(getParametr())!=J::objects.end()){
        delete J::objects[getParametr()];
        J::objects.erase(J::objects.find(getParametr()));
        cout<<"Usunąłeś obiekt o nazwie "<<getParametr()<<" z liścia "<<A::getWezel()<<endl;
      }
      else cout<<"Nie masz obiektu o takiej nazwie w tym węźle!"<<endl;
    }
    else{
      cout<<"Nie można usunąć obiektu, nie jesteś w liściu!"<<endl;
    }
  }

//metoda wypisująca obiekty danego węzła i jego potomków
  void dir(){
    if(A::getWezel() == "E"){
      if(!E::objects.empty()){ // sprawdzam czy liść zawiera obiekty
        cout<<"Węzeł "<<A::getWezel()<<" zawiera obiekty o nazwach: ";
        for(auto& x : E::objects){ //auto listuje po całej mapie zmieniając iterator x
          cout<<x.first<<", "; //first to nazwa obiektu
        } // wpisujemy wszytskie obiekty dla liścia
        cout<<endl;
      }
      else   cout<<"Węzeł "<<A::getWezel()<<" nie zawiera żadnych obiektów!"<<endl;
    }
    else if(A::getWezel() == "F"){
      if(!F::objects.empty()){
        cout<<"Węzeł "<<A::getWezel()<<" zawiera obiekty o nazwach: ";
        for(auto& x : F::objects){ //auto listuje po całej mapie zmieniając iterator x
          cout<<x.first<<", "; //first to nazwa obiektu
        } // wpisujemy wszytskie obiekty dla liścia
        cout<<endl;
      }
      else   cout<<"Węzeł "<<A::getWezel()<<" nie zawiera żadnych obiektów!"<<endl;
    }
    else if(A::getWezel() == "H"){
      if(!H::objects.empty()){
        cout<<"Węzeł "<<A::getWezel()<<" zawiera obiekty o nazwach: ";
        for(auto& x : H::objects){ //auto listuje po całej mapie zmieniając iterator x
          cout<<x.first<<", "; //first to nazwa obiektu
        } // wpisujemy wszytskie obiekty dla liścia
        cout<<endl;
      }
      else   cout<<"Węzeł "<<A::getWezel()<<" nie zawiera żadnych obiektów!"<<endl;
    }
    else if(A::getWezel() == "I"){
      if(!I::objects.empty()){
        cout<<"Węzeł "<<A::getWezel()<<" zawiera obiekty o nazwach: ";
        for(auto& x : I::objects){ //auto listuje po całej mapie zmieniając iterator x
          cout<<x.first<<", "; //first to nazwa obiektu
        } // wpisujemy wszytskie obiekty dla liścia
        cout<<endl;
      }
      else   cout<<"Węzeł "<<A::getWezel()<<" nie zawiera żadnych obiektów!"<<endl;
    }
    else if(A::getWezel() == "J"){
      if(!J::objects.empty()){
        cout<<"Węzeł "<<A::getWezel()<<" zawiera obiekty o nazwach: ";
        for(auto& x : J::objects){ //auto listuje po całej mapie zmieniając iterator x
          cout<<x.first<<", "; //first to nazwa obiektu
        } // wpisujemy wszytskie obiekty dla liścia
        cout<<endl;
      }
      else   cout<<"Węzeł "<<A::getWezel()<<" nie zawiera żadnych obiektów!"<<endl;
    }
    else if(A::getWezel() == "A"){
      if(!I::objects.empty() || !J::objects.empty() || !E::objects.empty()
           || !F::objects.empty() || !H::objects.empty()){
        cout<<"Węzeł "<<A::getWezel()<<" zawiera obiekty o nazwach: ";
        for(auto& x : I::objects){ //auto listuje po całej mapie zmieniając iterator x
          cout<<x.first<<", "; //first to nazwa obiektu
        } // wpisujemy wszytskie obiekty dla liścia
        for(auto& x : J::objects){ //auto listuje po całej mapie zmieniając iterator x
          cout<<x.first<<", "; //first to nazwa obiektu
        } // wpisujemy wszytskie obiekty dla liścia
        for(auto& x : E::objects){ //auto listuje po całej mapie zmieniając iterator x
          cout<<x.first<<", "; //first to nazwa obiektu
        } // wpisujemy wszytskie obiekty dla liścia
        for(auto& x : F::objects){ //auto listuje po całej mapie zmieniając iterator x
          cout<<x.first<<", "; //first to nazwa obiektu
        } // wpisujemy wszytskie obiekty dla liścia
        for(auto& x : H::objects){ //auto listuje po całej mapie zmieniając iterator x
          cout<<x.first<<", "; //first to nazwa obiektu
        } // wpisujemy wszytskie obiekty dla liścia
        cout<<endl;
      }
      else   cout<<"Węzeł "<<A::getWezel()<<" nie zawiera żadnych obiektów!"<<endl;
    }
    else if(A::getWezel() == "B"){
      if(!I::objects.empty() || !J::objects.empty()){
        cout<<"Węzeł "<<A::getWezel()<<" zawiera obiekty o nazwach: ";
        for(auto& x : I::objects){ //auto listuje po całej mapie zmieniając iterator x
          cout<<x.first<<", "; //first to nazwa obiektu
        } // wpisujemy wszytskie obiekty dla liścia
        for(auto& x : J::objects){ //auto listuje po całej mapie zmieniając iterator x
          cout<<x.first<<", "; //first to nazwa obiektu
        } // wpisujemy wszytskie obiekty dla liścia
        cout<<endl;
      }
      else   cout<<"Węzeł "<<A::getWezel()<<" nie zawiera żadnych obiektów!"<<endl;
    }
    else if(A::getWezel() == "C"){
      if(!E::objects.empty()){
        cout<<"Węzeł "<<A::getWezel()<<" zawiera obiekty o nazwach: ";
        for(auto& x : E::objects){ //auto listuje po całej mapie zmieniając iterator x
          cout<<x.first<<", "; //first to nazwa obiektu
        } // wpisujemy wszytskie obiekty dla liścia
        cout<<endl;
      }
      else   cout<<"Węzeł "<<A::getWezel()<<" nie zawiera żadnych obiektów!"<<endl;
    }
    else if(A::getWezel() == "D"){
      if(!H::objects.empty() || !J::objects.empty()){
        cout<<"Węzeł "<<A::getWezel()<<" zawiera obiekty o nazwach: ";
        for(auto& x : H::objects){ //auto listuje po całej mapie zmieniając iterator x
          cout<<x.first<<", "; //first to nazwa obiektu
        } // wpisujemy wszytskie obiekty dla liścia
        for(auto& x : J::objects){ //auto listuje po całej mapie zmieniając iterator x
          cout<<x.first<<", "; //first to nazwa obiektu
        } // wpisujemy wszytskie obiekty dla liścia
        cout<<endl;
      }
      else   cout<<"Węzeł "<<A::getWezel()<<" nie zawiera żadnych obiektów!"<<endl;
    }
    else if(A::getWezel() == "G"){
      if(!E::objects.empty()){
        cout<<"Węzeł "<<A::getWezel()<<" zawiera obiekty o nazwach: ";
        for(auto& x : J::objects){ //auto listuje po całej mapie zmieniając iterator x
          cout<<x.first<<", "; //first to nazwa obiektu
        } // wpisujemy wszytskie obiekty dla liścia
        cout<<endl;
      }
      else   cout<<"Węzeł "<<A::getWezel()<<" nie zawiera żadnych obiektów!"<<endl;
    }
    else{
      cout<<"Nie można wyświetlić obiektów, brak takiego węzła!"<<endl;
    }
  }
//metoda modyfikująca obiekt
  void mdo(){
    if(A::getWezel() == "E"){
      if(E::objects.find(getParametrN(1))!=E::objects.end()){ //sprawdzam czy istenie w liściu taki obiekt
        E *actn = E::objects[getParametr()];
        actn -> setX(getParametrN(2)); // nadajemy wartość paramwtrów x i y
        actn -> sete(getParametrN(3));
        actn -> seta(getParametrN(4));
        actn -> setc(getParametrN(5));
        cout<<"Wartosci nowych parametrow to : "<<actn -> getX()<<", "<<actn -> gete()<<", "<<actn -> getc()<<", "<<actn -> geta()<<endl;
      } else{
        cout<<"Brak takiego obiektu!"<<endl;
      }
    }
    else if(A::getWezel() == "F"){
      if(F::objects.find(getParametrN(1))!=F::objects.end()){
        F *actn = F::objects[getParametr()];
        actn -> setX(getParametrN(2)); // nadajemy wartość paramwtrów x i y
        actn -> setf(getParametrN(3));
        actn -> seta(getParametrN(4));
        actn -> setc(getParametrN(5));
        cout<<"Wartosci nowych parametrow to : "<<actn -> getX()<<", "<<actn -> getf()<<", "<<actn -> getc()<<", "<<actn -> geta()<<endl;
      } else{
        cout<<"Brak takiego obiektu!"<<endl;
      }
    }
    else if(A::getWezel() == "H"){
      if(H::objects.find(getParametrN(1))!=H::objects.end()){
        H *actn = H::objects[getParametr()];
        actn -> setX(getParametrN(2)); // nadajemy wartość paramwtrów x i y
        actn -> seth(getParametrN(3));
        actn -> seta(getParametrN(4));
        actn -> setd(getParametrN(5));
        cout<<"Wartosci nowych parametrow to : "<<actn -> getX()<<", "<<actn -> geth()<<", "<<actn -> getd()<<", "<<actn -> geta()<<endl;
      } else{
        cout<<"Brak takiego obiektu!"<<endl;
      }
    }
    else if(A::getWezel() == "I"){
      if(I::objects.find(getParametrN(1))!=I::objects.end()){
        I *actn = I::objects[getParametr()];
        actn -> setX(getParametrN(2)); // nadajemy wartość paramwtrów x i y
        actn -> seti(getParametrN(3));
        actn -> seta(getParametrN(4));
        actn -> setb(getParametrN(5));
        actn -> setc(getParametrN(6));
        cout<<"Wartosci nowych parametrow to : "<<actn -> getX()<<", "<<actn -> geti()<<", "<<actn -> getb()<<", "<<actn -> B::geta()<<", "<<actn -> getc()<<endl;
      } else{
        cout<<"Brak takiego obiektu!"<<endl;
      }
    }
    else if(A::getWezel() == "J"){
      if(J::objects.find(getParametr())!=J::objects.end()){
        J *actn = J::objects[getParametr()];
        actn -> setj(getParametrN(3));
        actn -> seta(getParametrN(4));
        actn -> setb(getParametrN(5));
        actn -> setg(getParametrN(6));
        actn -> setd(getParametrN(7));
        cout<<"Wartosci nowych parametrow to : "<<actn -> getX()<<", "<<actn -> getj()<<", "<<actn -> getb()<<", "<<actn -> B::geta()<<", "<<actn -> getg()<<", "<<actn -> getd()<<endl;
      } else{
        cout<<"Brak takiego obiektu!"<<endl;
      }
    }
    else{
      cout<<"Nie można usunąć obiektu, nie jesteś w liściu!"<<endl;
    }
  }
//metoda wyświetlająca szczegóły obiektu
  void show(){
    if( E::objects.find(getParametr()) != E::objects.end()){// sprawdzam czy dany węzeł ma obiekt o danej nazwie
      E *actn = E::objects[getParametrN(1)];
      cout<<"Nazwa obiektu to: "<<E::objects[getParametrN(1)] -> getName()<<", a parametry to "<<actn -> getX()<<", "<<actn -> gete()<<", "<<actn -> getc()<<", "<<actn -> geta()<<endl;
    }
    else if(F::objects.find(getParametr()) != F::objects.end()){
      F *actn = F::objects[getParametrN(1)];
      cout<<"Nazwa obiektu to: "<<F::objects[getParametrN(1)] -> getName()<<", a parametry to "<<actn -> getX()<<", "<<actn -> getf()<<", "<<actn -> getc()<<", "<<actn -> geta()<<endl;
    }
    else if(H::objects.find(getParametr()) != H::objects.end()){
      H *actn = H::objects[getParametrN(1)];
      cout<<"Nazwa obiektu to: "<<H::objects[getParametrN(1)] -> getName()<<", a parametry to "<<actn -> getX()<<", "<<actn -> geth()<<", "<<actn -> getd()<<", "<<actn -> geta()<<endl;
    }
    else if(I::objects.find(getParametr()) != I::objects.end()){
      I *actn = I::objects[getParametrN(1)];
      cout<<"Nazwa obiektu to: "<<I::objects[getParametrN(1)] -> getName()<<", a parametry to "<<actn -> getX()<<", "<<actn -> geti()<<", "<<actn -> getb()<<", "<<actn -> geta()<<", "<<actn -> getc()<<endl;
    }
    else if(J::objects.find(getParametr()) != J::objects.end()){
      J *actn = J::objects[getParametrN(1)];
      cout<<"Nazwa obiektu to: "<<J::objects[getParametrN(1)] -> getName()<<", a parametry to "<<actn -> getX()<<", "<<actn -> getj()<<", "<<actn -> getb()<<", "<<actn -> geta()<<", "<<actn -> getg()<<", "<<actn -> getd()<<endl;
    }
    else cout<<"Nie ma obiektu o nazwie "<<getParametrN(1)<<endl;
  }

//metoda zapisująca wszystkie obiekty do pliku
  void savee(){
    fstream plik;
    plik.open("data.txt", ios::out);
    plik<<"";
    plik.close();
      if(!E::objects.empty()){ // sprawdzam czy liść ma jakieś obiekty
        cout<<"Zapisano obiekty klasy E o nazwie: ";
        fstream plik;
        plik.open("data.txt", ios::out|ios::app); // otwieram plik
        for(auto& x : E::objects){ // iteruje po mapie
          plik<<"E "<<x.first<<" "<<x.second -> getX()<<" "<<x.second -> gete()<<" "<<x.second -> geta()<<" "<<x.second -> getc()<<endl; // zapisuję do jednej linijki wsyztskie informacje o obiekcie
          cout<<x.first + ", ";
        }
        plik.close();
        cout<<endl;
      }
      if(!F::objects.empty()){
        cout<<"Zapisano obiekty klasy F o nazwie: ";
        fstream plik;
        plik.open("data.txt", ios::out|ios::app); // otwieram plik
        for(auto& x : F::objects){ // iteruje po mapie
          plik<<"F "<<x.first<<" "<<x.second -> getX()<<" "<<x.second -> getf()<<" "<<x.second -> geta()<<" "<<x.second -> getc()<<endl; // zapisuję do jednej linijki wsyztskie informacje o obiekcie
          cout<<x.first + ", ";
        }
        plik.close();
        cout<<endl;
      }
      if(!H::objects.empty()){
        cout<<"Zapisano obiekty klasy H o nazwie: ";
        fstream plik;
        plik.open("data.txt", ios::out|ios::app); // otwieram plik
        for(auto& x : H::objects){ // iteruje po mapie
          plik<<"H "<<x.first<<" "<<x.second -> getX()<<" "<<x.second -> geth()<<" "<<x.second -> geta()<<" "<<x.second -> getd()<<endl; // zapisuję do jednej linijki wsyztskie informacje o obiekcie
          cout<<x.first + ", ";
        }
        plik.close();
        cout<<endl;
      }
      if(!I::objects.empty()){
        cout<<"Zapisano obiekty klasy I o nazwie: ";
        fstream plik;
        plik.open("data.txt", ios::out|ios::app); // otwieram plik
        for(auto& x : I::objects){ // iteruje po mapie
          plik<<"I "<<x.first<<" "<<x.second -> getX()<<" "<<x.second -> geti()<<" "<<x.second -> geta()<<" "<<x.second -> getb()<<" "<<x.second -> getc()<<endl; // zapisuję do jednej linijki wsyztskie informacje o obiekcie
          cout<<x.first + ", ";
        }
        plik.close();
        cout<<endl;
      }
      if(!J::objects.empty()){
        cout<<"Zapisano obiekty klasy J o nazwie: ";
        fstream plik;
        plik.open("data.txt", ios::out|ios::app); // otwieram plik
        for(auto& x : J::objects){ // iteruje po mapie
          plik<<"J "<<x.first<<" "<<x.second -> getX()<<" "<<x.second -> getj()<<" "<<x.second -> geta()<<" "<<x.second -> getb()<<" "<<x.second -> getg()<<" "<<x.second -> getd()<<endl; // zapisuję do jednej linijki wsyztskie informacje o obiekcie
          cout<<x.first + ", ";
        }
        plik.close();
        cout<<endl;
      }
      if(E::objects.empty() && F::objects.empty()
        && H::objects.empty() && I::objects.empty()
         && J::objects.empty())
         cout<<"Nie ma żadnych obiektów do zapisu!"<<endl;
  }



  void createRead(string tax[]){
    if(tax[0] == "E"){
       E *actn = new E(tax[1]); //tworzymy nowy obiekt
       E::objects[tax[1]]= actn; // dodajemy do mapy obiektów
       actn -> setX(tax[2]); // nadajemy wartość paramwtrów x i y
       actn -> sete(tax[3]);
       actn -> seta(tax[4]);
       actn -> setc(tax[5]);
       cout<<"Dodałeś obiekt o nazwie "<<actn ->getName()<<" do liścia "<<tax[0]<<" o parametrach "<<actn -> getX()<<", "<<actn -> gete()<<", "<<actn -> getc()<<", "<<actn -> geta()<<endl;
     }
     else if(tax[0] == "F"){
       F *actn = new F(tax[1]);
       F::objects[tax[1]]= actn;
       actn -> setX(tax[2]); // nadajemy wartość paramwtrów x i y
       actn -> setf(tax[3]);
       actn -> seta(tax[4]);
       actn -> setc(tax[5]);
       cout<<"Dodałeś obiekt o nazwie "<<actn ->getName()<<" do liścia "<<tax[0]<<" o parametrach "<<actn -> getX()<<", "<<actn -> getf()<<", "<<actn -> getc()<<", "<<actn -> geta()<<endl;
     }
     else if(tax[0] == "H"){
       H *actn = new H(tax[1]);
       H::objects[tax[1]]= actn;
       actn -> setX(tax[2]); // nadajemy wartość paramwtrów x i y
       actn -> seth(tax[3]);
       actn -> seta(tax[4]);
       actn -> setd(tax[5]);
       cout<<"Dodałeś obiekt o nazwie "<<actn ->getName()<<" do liścia "<<tax[0]<<" o parametrach "<<actn -> getX()<<", "<<actn -> geth()<<", "<<actn -> getd()<<", "<<actn -> geta()<<endl;
     }
     else if(tax[0] == "I"){
       I *actn = new I(tax[1]);
       I::objects[tax[1]]= actn;
       actn -> setX(tax[2]); // nadajemy wartość paramwtrów x i y
       actn -> seti(tax[3]);
       actn -> seta(tax[4]);
       actn -> setb(tax[5]);
       actn -> setc(tax[6]);
       cout<<"Dodałeś obiekt o nazwie "<<actn ->getName()<<" do liścia "<<tax[0]<<" o parametrach "<<actn -> getX()<<", "<<actn -> geti()<<", "<<actn -> getb()<<", "<<actn -> geta()<<", "<<actn -> getc()<<endl;
     }
     else if(tax[0] == "J"){
       J *actn = new J(tax[1]);
       J::objects[tax[1]]= actn;
       actn -> setX(tax[2]);
       actn -> setj(tax[3]);
       actn -> seta(tax[4]);
       actn -> setb(tax[5]);
       actn -> setg(tax[6]);
       actn -> setd(tax[7]);
       cout<<"Dodałeś obiekt o nazwie "<<actn ->getName()<<" do liścia "<<tax[0]<<" o parametrach "<<actn -> getX()<<", "<<actn -> getj()<<", "<<actn -> getb()<<", "<<actn -> geta()<<", "<<actn -> getg()<<", "<<actn -> getd()<<endl;
     }
     else{
       cout<<"Nie można stworzyć obiektu, nie ma takiego liścia!"<<endl;
     }
   }



  //metoda wczytująca obiekty z pliku
  void readd(){
    string ww = A::getWezel();
    fstream plik;
    plik.open("data.txt", ios::in); //otwarcie pliku
      while(!plik.eof()){
        string linia = "";
        getline(plik,linia);
        if(linia!=""){//jeśli pusta linijka to klasa będzie mieć wartość none, więc nie będzie tworzyć nowej klasy, zlikwidowało to podwójne tworzenie ostatniej klasy w pliku
          int i = 0, j = 0;
          string tax[20];
          while(i < linia.size()){
          if(linia[i] == ' '){
            i++; j++;
          }
          tax[j] += linia[i];//zczytywanie litera po literze i dodawanie do stringa aż nie będzie spacji
          i++;
          }
          createRead(tax);
        }
      }
    A::setWezel(ww);
  }
//metoda wypisująca drzewo dizedziczenia
  void tree(){
    cout<<"A"<<endl
      <<"-B"<<endl
        <<"--I"<<endl
        <<"--J"<<endl
      <<"-C"<<endl
        <<"--E"<<endl
        <<"--F"<<endl
        <<"--I"<<endl
      <<"-D"<<endl
        <<"--G"<<endl
          <<"---J"<<endl
        <<"--H"<<endl;
  }

};

int main(){
    do{
      cout<<"Liczba argumentów: E(5), F(5), H(5), I(6), J(7)"<<endl;
      Polecenie *pol = new Polecenie();
      pol -> proceed();
      delete pol;
    }while(1);
  return 0;
}
