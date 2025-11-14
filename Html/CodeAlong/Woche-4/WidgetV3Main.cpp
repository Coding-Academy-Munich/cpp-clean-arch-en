#include "WidgetV3.h"
#include <iostream>

using widget_v3::WidgetV3;

int main() {
    WidgetV3 w;
    std::cout << "Non-const WidgetV3\n";
    w.PrintWidget();
    w.SetState(42);
    std::cout << "State is: " << w.GetState() << "\n";
    w.PrintWidget();

    const WidgetV3 w2;
    std::cout << "Const WidgetV3\n";
    w2.PrintWidget();
    // w2.SetState(42);
    std::cout << "State is: " << w2.GetState() << "\n";
    w2.PrintWidget();
}