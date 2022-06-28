#include <vector>
#include <iostream>
#include <memory>                    // shared_ptr
#include <random>                    // uniform_int_distribution, random_device
namespace {                          // Beginn des anonymen Namensraums
    using std::shared_ptr; using std::make_shared;
    using std::vector; using std::cout;

    struct Asteroid {
        int points_ = 100;
        int structure_ = 10;
    };
    struct Ship {
        shared_ptr<Asteroid> firedLastOn_{};
        int score_ = 0;
        int firepower = 1;
        bool fireUpon(shared_ptr<Asteroid> a);
    };

    struct GameBoard {
        vector<shared_ptr<Asteroid>> asteroids_;
        explicit GameBoard(int nAsteroids);
        bool shipFires(Ship& ship);
    };

    // Implementierung Ship
    bool Ship::fireUpon(shared_ptr<Asteroid> a) {
        if (!a) return false;             // ungültiger Asteroid
        a->structure_ -= firepower;
        if (a.get() == firedLastOn_.get())
            firepower *= 2;             // Schaden vergrößern
        else
            firepower = 1;               // zurücksetzen
        firedLastOn_ = a;
        return a->structure_ <= 0;       // kaputt?
    }

    // Implementierung GameBoard
    GameBoard::GameBoard(int nAsteroids)
        : asteroids_{}
    {   // einige Standard-Asteroiden
        for (int idx = 0; idx < nAsteroids; ++idx)
            asteroids_.push_back(make_shared<Asteroid>());
    }
    int wuerfel(int min, int max) {
        /* static std::default_random_engine e{}; */     // Pseudo-Zufallsgenerator
        static std::random_device e{};                          // Zufallsgenerator
        return std::uniform_int_distribution<int>{min, max}(e); // würfeln
    }

    bool GameBoard::shipFires(Ship& ship) {
        int idx = wuerfel(0, asteroids_.size() - 1);
        bool kaputt = ship.fireUpon(asteroids_[idx]);
        if (kaputt) {
            ship.score_ += asteroids_[idx]->points_;
            asteroids_.erase(asteroids_.begin() + idx);           // entfernen
        }
        return asteroids_.size() == 0;                          // alles kaputt
    }

} // Ende des anonymen Namensraums

int main() {
    GameBoard game{ 10 };                                     // 10 Asteroiden
    Ship ship{};
    for (int idx = 0; idx < 85; ++idx) {                     // 85 Schüsse
        if (game.shipFires(ship)) {
            cout << "Der Weltraum ist nach " << idx + 1 << " Schuessen leer. ";
            break;
        }
    }
    cout << "Sie haben " << ship.score_ << " Punkte erreicht.\n";
}




