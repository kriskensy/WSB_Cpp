#include <iostream>
#include <string>

class Pojazd {
private:
    float waga;
    int liczbaKol;
public:
    Pojazd(float waga, int liczbaKol) : waga(waga), liczbaKol(liczbaKol) {}
    float getWaga() const { return waga; }
    int getLiczbaKol() const { return liczbaKol; }
};

class Motocykl : public Pojazd {
private:
    std::string nrRej;
    int mocSilnika;
public:
    Motocykl() : Pojazd(0, 2), nrRej("brak"), mocSilnika(0) {}
    Motocykl(float waga, int liczbaKol, std::string nrRej, int mocSilnika)
        : Pojazd(waga, liczbaKol), nrRej(nrRej), mocSilnika(mocSilnika) {}
    std::string getNrRej() const { return nrRej; }
    int getMocSilnika() const { return mocSilnika; }
    void wyswietl() const {
        std::cout << nrRej << " " << mocSilnika << " "
            << getWaga() << " " << getLiczbaKol() << " ";
    }
};

class KatalogMotocykli {
private:
    Motocykl motocykle[20];
    int liczbaMotocykli;
public:
    KatalogMotocykli() : liczbaMotocykli(0) {}
    void dodajMotocykl(Motocykl m) {
        if (liczbaMotocykli < 20) {
            int i = liczbaMotocykli;
            while (i > 0 && (m.getMocSilnika() > motocykle[i-1].getMocSilnika()
                || (m.getMocSilnika() == motocykle[i-1].getMocSilnika()
                    && m.getWaga() < motocykle[i-1].getWaga()))) {
                motocykle[i] = motocykle[i-1];
                --i;
            }
            motocykle[i] = m;
            ++liczbaMotocykli;
        }
    }
    void wyswietl() const {
        for (int i = 0; i < liczbaMotocykli; ++i) {
            motocykle[i].wyswietl();
        }
    }
};

int main() {
    KatalogMotocykli katalog;
    for (int i = 0; i < 6; ++i) {
        float waga;
        int liczbaKol, mocSilnika;
        std::string nrRej;
        std::cin >> waga >> liczbaKol >> nrRej >> mocSilnika;
        Motocykl m(waga, liczbaKol, nrRej, mocSilnika);
        katalog.dodajMotocykl(m);
    }
    katalog.wyswietl();
    return 0;
}
