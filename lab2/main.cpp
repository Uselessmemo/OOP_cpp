#include <iostream>
#include <cmath>

#define PI 3.14159265

using namespace std;

class Triangl {
    private:
        double a, b, c;
        double perimetr, area;
        double alpha, beta, gama;
    public:
        void set_trian(double aa, double bb, double cc);

        Triangl();
        Triangl(double aa, double bb, double cc);
        Triangl(const Triangl& obj);
        ~Triangl();

        bool trian_exists() const;
        void get_sides() const;
        void get_angles() ;
        void get_perimetr();
        void get_area();
};

bool Triangl::trian_exists() const {
    bool ans = 1;
    if ((a + b <= c || a + c <= b || b + c <= a) || (a == 0 || b == 0 || c == 0))
        ans = 0;
    return ans;
}

void Triangl::set_trian(double aa, double bb, double cc) {
    if (aa < 0)
        aa = 0;
    if (bb < 0)
        bb = 0;
    if (cc < 0)
        cc = 0;
    a = aa;
    b = bb;
    c = cc;
}

Triangl::Triangl() {
    cout << "Стандартный конструктор\n";
    set_trian(1, 1, 1);
}

Triangl::Triangl(double aa, double bb, double cc){
    cout << "Конструктор с параметрами\n";
    set_trian(aa, bb, cc);
}

Triangl::Triangl(const Triangl& obj) {
    cout << "Конструктор копирования\n";
    set_trian(obj.a, obj.b, obj.c);
}

Triangl::~Triangl() {
    cout << "Очистка памяти" << endl;
}

void Triangl::get_sides() const {
    cout << "a = " << a << " b = " << b << " c = " << c << endl;
}

void Triangl::get_angles() {
    gama = acos((a * a + b * b - c * c) / (2 * a * b)) * 180 / PI;
    alpha = acos((c * c + b * b - a * a) / (2 * c * b)) * 180 / PI;
    beta = acos((c * c + a * a - b * b) / (2 * c * a)) * 180 / PI;
    cout << "alpha = " << alpha << " beta = " << beta << " gama = " << gama << endl;
}

void Triangl::get_perimetr() {
    perimetr = a + b + c;
    cout << "perimetr = " << perimetr << endl;
}

void Triangl::get_area() {
    area = a * b * sin(gama / 180 * PI) / 2;
    cout << "area = " << area << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    double a, b, c;
    cout << "Задайте стороны треугольника\n";
    cin >> a >> b >> c;
    Triangl example = Triangl(a, b, c);

    while (!example.trian_exists()) {
        cout << "Задайте стороны треугольника\n";
        cin >> a >> b >> c;
        example.set_trian(a, b, c);
    }
    cout << "Вывод сведений о треугольнике №1\n";
    example.get_sides();
    example.get_angles();
    example.get_perimetr();
    example.get_area();
    cout << "\n";

    Triangl example2 = Triangl();
    cout << "Вывод сведений о треугольнике №2\n";
    example2.get_sides();
    example2.get_angles();
    example2.get_perimetr();
    example2.get_area();
    cout << "\n";

    Triangl example3 = Triangl(example);
    cout << "Вывод сведений о треугольнике №3\n";
    example3.get_sides();
    example3.get_angles();
    example3.get_perimetr();
    example3.get_area();
    cout << "\n";

    return 0;
}

