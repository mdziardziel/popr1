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
  string z;
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
  virtual void setZ(string z){
    this -> z = z;
  }
  virtual string getZ(){
    return z;
  }
};

class B : public A{
private:
  string x;
protected:
  string z;
protected:
  B(){}
  ~B(){}
};

class C : public A{
private:
  string x;
protected:
  string z;
protected:
  C(){}
  ~C(){}
};

class D : public A{
private:
  string x;
protected:
  string z;
protected:
  D(){}
  ~D(){}
};

class E : public C{
private:
  string x;
protected:
  string z;
public:
  E(string name){
      this -> A::name = name;
  }
  ~E(){}
  static map<string, A*> objects;
};

class F : public C{
private:
  string x;
protected:
  string z;
public:
  F(string name){
      this -> A::name = name;
  }
  ~F(){}
  static map<string, A*> objects;
};

class G : public D{
private:
  string x;
protected:
  string z;
protected:
  G(){}
  ~G(){}
public:
};

class H : public D{
private:
  string x;
protected:
  string z;
public:
  H(string name){
      this -> A::name = name;
  }
  ~H(){}
  static map<string, A*> objects;
};

class I : public B,  public C{
private:
  string x;
protected:
  string z;
public:
  I(string name){
      this -> B::name = name;
  }
  ~I(){}
  static map<string, A*> objects;
};

class J : public B, public G{
private:
  string x;
protected:
  string z;
public:
  J(string name){
    this -> B::name = name;
  }
  ~J(){}
  static map<string, A*> objects;
};


map<string, A*> E::objects;//inicjowanie statycznych map
map<string, A*> F::objects;
map<string, A*> H::objects;
map<string, A*> I::objects;
map<string, A*> J::objects;
string A::wezel;

class Polecenie{
/*
Ta klasa obpowiada za pobieranie i przetwarzanie komend z terminala;
W konstruktorze pobieramy polecenie z terminala
*/
private:
    string polecenie, komenda, parametr, parametr1, parametr2;
public:
  Polecenie(){
    setPolecenie();
    int i = 0;
    while(polecenie[i] != ' ' && i < polecenie.size()){
      komenda += polecenie[i];//zczytywanie litera po literze i dodawanie do stringa aż nie będzie spacji
      i++;
    }
    i++;
    while(polecenie[i] != ' ' && i < polecenie.size()){
      parametr += polecenie[i];
      i++;
    }
    i++;
    while(polecenie[i] != ' ' && i < polecenie.size()){
      parametr1 += polecenie[i];
      i++;
    }
    i++;
    while(polecenie[i] != ' ' && i < polecenie.size()){
      parametr2 += polecenie[i];
      i++;
    }
  }/*
  Polecenie(string polecenie){
    this -> polecenie = polecenie;
    int i = 0;
    while(polecenie[i] != '(' && i < polecenie.size()){
      komenda += polecenie[i];
      i++;
    }
    i++;
    while(polecenie[i] != ')' && i < polecenie.size()){
      parametr += polecenie[i];
      i++;
    }
    i++;
    while(polecenie[i] != ' '&& i < polecenie.size()){
      parametr1 += polecenie[i];
      i++;
    }
    i++;
    while(polecenie[i] != ' ' && i < polecenie.size()){
      parametr1 += polecenie[i];
      i++;
    }
  }*/
  ~Polecenie(){}

  string getPolecenie(){
    return polecenie;
  }

  void setPolecenie(){
    //cin>>polecenie;
    getline(cin,polecenie);
    cout<<endl;
  }
  void setParametr(string parametr){
    this -> parametr = parametr;
  }

  string getKomenda(){
    return komenda;
  }

  string getParametr(){
    return parametr;
  }

  string getParametr1(){
    return parametr1;
  }

  string getParametr2(){
    return parametr2;
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
    string liscie[5] = {"E","F","H","I","J"}; //tablica liści
    map<string, A*> objects;
    map<string, A*> tab[5] = {E::objects, F::objects,H::objects,I::objects,J::objects}; // 5 elementowa tablica map
    for(int i = 0; i < 5; i++){
      A::setWezel(liscie[i]);// nadajemy ity liść
      objects = tab[i]; // nadajemy mapę dla danego liścia
      for(auto& x : objects){ // przejeżdzamy się po wszystkich obiektach w mapie i usuwamy
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
      E *actn = new E(getParametr()); //tworzymy nowy obiekt
      E::objects[getParametr()]= actn; // dodajemy do mapy obiektów
      actn -> setX(getParametr1()); // nadajemy wartość paramwtrów x i y
      actn -> setZ(getParametr2());
      cout<<"Dodałeś obiekt o nazwie "<<actn ->getName()<<" do liścia "<<A::getWezel()<<" o parametrach "<<actn -> getX()<<", "<<actn -> getZ()<<endl;
    }
    else if(A::getWezel() == "F"){
      F *actn = new F(getParametr());
      F::objects[getParametr()]= actn;
      actn -> setX(getParametr1());
      actn -> setZ(getParametr2());
      cout<<"Dodałeś obiekt o nazwie "<<actn ->getName()<<" do liścia "<<A::getWezel()<<" o parametrach "<<actn -> getX()<<", "<<actn -> getZ()<<endl;
    }
    else if(A::getWezel() == "H"){
      H *actn = new H(getParametr());
      H::objects[getParametr()]= actn;
      actn -> setX(getParametr1());
      actn -> setZ(getParametr2());
      cout<<"Dodałeś obiekt o nazwie "<<actn ->getName()<<" do liścia "<<A::getWezel()<<" o parametrach "<<actn -> getX()<<", "<<actn -> getZ()<<endl;
    }
    else if(A::getWezel() == "I"){
      B *actn = new I(getParametr());
      I::objects[getParametr()]= actn;
      actn -> setX(getParametr1());
      actn -> setZ(getParametr2());
      cout<<"Dodałeś obiekt o nazwie "<<actn ->getName()<<" do liścia "<<A::getWezel()<<" o parametrach "<<actn -> getX()<<", "<<actn -> getZ()<<endl;
    }
    else if(A::getWezel() == "J"){
      B *actn = new J(getParametr());
      J::objects[getParametr()]= actn;
      actn -> setX(getParametr1());
      actn -> setZ(getParametr2());
      cout<<"Dodałeś obiekt o nazwie "<<actn ->getName()<<" do liścia "<<A::getWezel()<<" o parametrach "<<actn -> getX()<<", "<<actn -> getZ()<<endl;
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
//metoda wypisująca wszystkie obiekty danego liścia
  void printObjects(map<string, A*> objects){
    for(auto& x : objects){ //auto listuje po całej mapie zmieniając iterator x
      cout<<x.first<<", "; //first to nazwa obiektu
    }
  }
//metoda wypisująca obiekty danego węzła i jego potomków
  void dir(){
    if(A::getWezel() == "E"){
      if(!E::objects.empty()){ // sprawdzam czy liść zawiera obiekty
        cout<<"Węzeł "<<A::getWezel()<<" zawiera obiekty o nazwach: ";
        printObjects(E::objects); // wpisujemy wszytskie obiekty dla liścia E
        cout<<endl;
      }
      else   cout<<"Węzeł "<<A::getWezel()<<" nie zawiera żadnych obiektów!"<<endl;
    }
    else if(A::getWezel() == "F"){
      if(!F::objects.empty()){
        cout<<"Węzeł "<<A::getWezel()<<" zawiera obiekty o nazwach: ";
        printObjects(F::objects);
        cout<<endl;
      }
      else   cout<<"Węzeł "<<A::getWezel()<<" nie zawiera żadnych obiektów!"<<endl;
    }
    else if(A::getWezel() == "H"){
      if(!H::objects.empty()){
        cout<<"Węzeł "<<A::getWezel()<<" zawiera obiekty o nazwach: ";
        printObjects(H::objects);
        cout<<endl;
      }
      else   cout<<"Węzeł "<<A::getWezel()<<" nie zawiera żadnych obiektów!"<<endl;
    }
    else if(A::getWezel() == "I"){
      if(!I::objects.empty()){
        cout<<"Węzeł "<<A::getWezel()<<" zawiera obiekty o nazwach: ";
        printObjects(I::objects);
        cout<<endl;
      }
      else   cout<<"Węzeł "<<A::getWezel()<<" nie zawiera żadnych obiektów!"<<endl;
    }
    else if(A::getWezel() == "J"){
      if(!J::objects.empty()){
        cout<<"Węzeł "<<A::getWezel()<<" zawiera obiekty o nazwach: ";
        printObjects(J::objects);
        cout<<endl;
      }
      else   cout<<"Węzeł "<<A::getWezel()<<" nie zawiera żadnych obiektów!"<<endl;
    }
    else if(A::getWezel() == "A"){
      if(!I::objects.empty() || !J::objects.empty() || !E::objects.empty()
           || !F::objects.empty() || !H::objects.empty()){
        cout<<"Węzeł "<<A::getWezel()<<" zawiera obiekty o nazwach: ";
        printObjects(I::objects);
        printObjects(J::objects);
        printObjects(E::objects);
        printObjects(F::objects);
        printObjects(H::objects);
        cout<<endl;
      }
      else   cout<<"Węzeł "<<A::getWezel()<<" nie zawiera żadnych obiektów!"<<endl;
    }
    else if(A::getWezel() == "B"){
      if(!I::objects.empty() || !J::objects.empty()){
        cout<<"Węzeł "<<A::getWezel()<<" zawiera obiekty o nazwach: ";
        printObjects(I::objects);
        printObjects(J::objects);
        cout<<endl;
      }
      else   cout<<"Węzeł "<<A::getWezel()<<" nie zawiera żadnych obiektów!"<<endl;
    }
    else if(A::getWezel() == "C"){
      if(!E::objects.empty()){
        cout<<"Węzeł "<<A::getWezel()<<" zawiera obiekty o nazwach: ";
        printObjects(E::objects);
        cout<<endl;
      }
      else   cout<<"Węzeł "<<A::getWezel()<<" nie zawiera żadnych obiektów!"<<endl;
    }
    else if(A::getWezel() == "D"){
      if(!H::objects.empty() || !J::objects.empty()){
        cout<<"Węzeł "<<A::getWezel()<<" zawiera obiekty o nazwach: ";
        printObjects(H::objects);
        printObjects(J::objects);
        cout<<endl;
      }
      else   cout<<"Węzeł "<<A::getWezel()<<" nie zawiera żadnych obiektów!"<<endl;
    }
    else if(A::getWezel() == "G"){
      if(!E::objects.empty()){
        cout<<"Węzeł "<<A::getWezel()<<" zawiera obiekty o nazwach: ";
        printObjects(J::objects);
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
      if(E::objects.find(getParametr())!=E::objects.end()){ //sprawdzam czy istenie w liściu taki obiekt
        E::objects[getParametr()]-> setX(getParametr1()); // zmieniam wartości parametrów
        E::objects[getParametr()]-> setZ(getParametr2());
        cout<<"Wartosci nowych parametrow to : "<<getParametr1()<<", "<<getParametr2()<<endl;
      } else{
        cout<<"Brak takiego obiektu!"<<endl;
      }
    }
    else if(A::getWezel() == "F"){
      if(F::objects.find(getParametr())!=F::objects.end()){
        F::objects[getParametr()]-> setX(getParametr1());
        F::objects[getParametr()]-> setZ(getParametr2());
        cout<<"Wartosci nowych parametrow to : "<<getParametr1()<<", "<<getParametr2()<<endl;
      } else{
        cout<<"Brak takiego obiektu!"<<endl;
      }
    }
    else if(A::getWezel() == "H"){
      if(H::objects.find(getParametr())!=H::objects.end()){
        H::objects[getParametr()]-> setX(getParametr1());
        H::objects[getParametr()]-> setZ(getParametr2());
        cout<<"Wartosci nowych parametrow to : "<<getParametr1()<<", "<<getParametr2()<<endl;
      } else{
        cout<<"Brak takiego obiektu!"<<endl;
      }
    }
    else if(A::getWezel() == "I"){
      if(I::objects.find(getParametr())!=I::objects.end()){
        I::objects[getParametr()]-> setX(getParametr1());
        I::objects[getParametr()]-> setZ(getParametr2());
        cout<<"Wartosci nowych parametrow to : "<<getParametr1()<<", "<<getParametr2()<<endl;
      } else{
        cout<<"Brak takiego obiektu!"<<endl;
      }
    }
    else if(A::getWezel() == "J"){
      if(J::objects.find(getParametr())!=J::objects.end()){
        J::objects[getParametr()]-> setX(getParametr1());
        J::objects[getParametr()]-> setZ(getParametr2());
        cout<<"Wartosci nowych parametrow to : "<<getParametr1()<<", "<<getParametr2()<<endl;
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
      cout<<"Nazwa obiektu to: "<<E::objects[getParametr()] -> getName()<<", a parametry to "<<E::objects[getParametr()] -> getX()<<", "<<E::objects[getParametr()] -> getZ()<<endl;
    }
    else if(F::objects.find(getParametr()) != F::objects.end()){
      cout<<"Nazwa obiektu to: "<<F::objects[getParametr()] -> getName()<<", a parametry to "<<F::objects[getParametr()] -> getX()<<", "<<F::objects[getParametr()] -> getZ()<<endl;
    }
    else if(H::objects.find(getParametr()) != H::objects.end()){
      cout<<"Nazwa obiektu to: "<<H::objects[getParametr()] -> getName()<<", a parametry to "<<H::objects[getParametr()] -> getX()<<", "<<H::objects[getParametr()] -> getZ()<<endl;
    }
    else if(I::objects.find(getParametr()) != I::objects.end()){
      cout<<"Nazwa obiektu to: "<<I::objects[getParametr()] -> getName()<<", a parametry to "<<I::objects[getParametr()] -> getX()<<", "<<I::objects[getParametr()] -> getZ()<<endl;
    }
    else if(J::objects.find(getParametr()) != J::objects.end()){
      cout<<"Nazwa obiektu to: "<<J::objects[getParametr()] -> getName()<<", a parametry to "<<J::objects[getParametr()] -> getX()<<", "<<J::objects[getParametr()] -> getZ()<<endl;
    }
    else cout<<"Nie ma obiektu o nazwie "<<getParametr()<<endl;
  }
//metoda zapisująca obiekty danego liścia do pliku
  void saveObjects(map<string, A*> objects, string klas){
    fstream plik;
    plik.open("data.txt", ios::out|ios::app); // otwieram plik
    for(auto& x : objects){ // iteruje po mapie
      plik<<x.first<<" "<<klas<<" "<<x.second -> getX()<<" "<<x.second -> getZ()<<endl; // zapisuję do jednej linijki wsyztskie informacje o obiekcie
      cout<<x.first + ", ";
    }
    plik.close();
  }
//metoda zapisująca wszystkie obiekty do pliku
  void savee(){
    fstream plik;
    plik.open("data.txt", ios::out);
    plik<<"";
    plik.close();
      if(!E::objects.empty()){ // sprawdzam czy liść ma jakieś obiekty
        cout<<"Zapisano obiekty klasy E o nazwie: ";
        saveObjects(E::objects,"E"); // zapisuję
        cout<<endl;
      }
      if(!F::objects.empty()){
        cout<<"Zapisano obiekty klasy F o nazwie: ";
        saveObjects(F::objects, "F");
        cout<<endl;
      }
      if(!H::objects.empty()){
        cout<<"Zapisano obiekty klasy H o nazwie: ";
        saveObjects(H::objects, "H");
        cout<<endl;
      }
      if(!I::objects.empty()){
        cout<<"Zapisano obiekty klasy I o nazwie: ";
        saveObjects(I::objects, "I");
        cout<<endl;
      }
      if(!J::objects.empty()){
        cout<<"Zapisano obiekty klasy J o nazwie: ";
        saveObjects(J::objects,"J");
        cout<<endl;
      }
      if(E::objects.empty() && F::objects.empty()
        && H::objects.empty() && I::objects.empty()
         && J::objects.empty())
         cout<<"Nie ma żadnych obiektów do zapisu!"<<endl;
  }
//metoda tworząca wczytane obiekty
  void createRead(string name, string klasa, string parametr1,string parametr2){
    if(klasa == "E"){ // sprawdzanie klasy
      E *actn = new E(name); //tworzenie nowego obiektu
      actn -> setX(parametr1); //nadawanie wartości parametrom
      actn -> setZ(parametr2);
      E::objects[name]= actn; // dopisywanie do mapy obiektóe
      cout<<"Stworzono obiekt klasy "<<klasa<<" o nazwie: "<<name<<" i parametrach : "<<actn -> getX()<<", "<<actn -> getZ()<<endl;
    }
    else if(klasa == "F"){
      F *actn = new F(name);
      actn -> setX(parametr1);
      actn -> setZ(parametr2);
      F::objects[name]= actn;
      cout<<"Stworzono obiekt klasy "<<klasa<<" o nazwie: "<<name<<" i parametrze : "<<actn -> getX()<<", "<<actn -> getZ()<<endl;
    }
    else if(klasa == "H"){
      H *actn = new H(name);
      actn -> setX(parametr1);
      actn -> setZ(parametr2);
      H::objects[name]= actn;
      cout<<"Stworzono obiekt klasy "<<klasa<<" o nazwie: "<<name<<" i parametrze : "<<actn -> getX()<<", "<<actn -> getZ()<<endl;
    }
    else if(klasa == "I"){
      B *actn = new I(name);
      actn -> setX(parametr1);
      actn -> setZ(parametr2);
      I::objects[name]= actn;
      cout<<"Stworzono obiekt klasy "<<klasa<<" o nazwie: "<<name<<" i parametrze : "<<actn -> getX()<<", "<<actn -> getZ()<<endl;
    }
    else if(klasa == "J"){
      B *actn = new J(name);
      actn -> setX(parametr1);
      actn -> setZ(parametr2);
      J::objects[name]= actn;
      cout<<"Stworzono obiekt klasy "<<klasa<<" o nazwie: "<<name<<" i parametrze : "<<actn -> getX()<<", "<<actn -> getZ()<<endl;
    }
    else{
      cout<<"Nie można stworzyć obiektu, nie ma takiego liścia!"<<endl;
    }
  }
  //metoda wczytująca obiekty z pliku
  void readd(){
    fstream plik;
    string name, klasa, parametr1;
    plik.open("data.txt", ios::in); //otwarcie pliku
    //if(plik.tellg() == 0) cout<<"Plik do odczytu jest pusty!"<<endl;
    //else{
      while(!plik.eof()){
        klasa = "none";
        plik>>name>>klasa>>parametr1>>parametr2; // zczytywanie pliku
        if(klasa!="none")//jeśli pusta linijka to klasa będzie mieć wartość none, więc nie będzie tworzyć nowej klasy, zlikwidowało to podwójne tworzenie ostatniej klasy w pliku
          createRead(name, klasa, parametr1,parametr2);
      }
  //  }
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
      Polecenie *pol = new Polecenie();
      pol -> proceed();
      delete pol;
    }while(1);
  return 0;
}
