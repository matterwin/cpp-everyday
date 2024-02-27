#include <iostream>
#include <memory> // include this to use std::unique_ptr
using namespace std;

class Fish {
public:
    Fish() { cout << "Fish: Constructed!" << endl; }
    ~Fish() { cout << "Fish: Destructed!" << endl; }

    void Swim() const { cout << "Fish swims in water" << endl; }
};

void MakeFishSwim(const unique_ptr<Fish>& inFish) {
    inFish->Swim();
}

int main() {
    unique_ptr<Fish> smartFish(new Fish);

    smartFish->Swim();
    MakeFishSwim(smartFish); // OK, as MakeFishSwim accepts reference

    unique_ptr<Fish> copySmartFish;
    // copySmartFish = smartFish; // error: operator= is private

    return 0;
}


// Fish: Constructed!
// Fish swims in water
// Fish swims in water
// Fish: Destructed!



