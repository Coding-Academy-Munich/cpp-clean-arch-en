#include "WidgetV1.h"

#include <iostream>

// %% tags=["keep", "subslide"]
class widget_v1::WidgetV1::Impl {
public:
    void PrintWidget() { std::cout << "Impl::PrintWidget(): " << state_ << "\n"; }

    int GetState() const { return state_; }

    void SetState(int state) { state_ = state; }

private:
    int state_{};
};

// %% tags=["keep", "subslide"]
namespace widget_v1 {
widget_v1::WidgetV1::WidgetV1() : pImpl{std::make_unique<Impl>()} {}
} // namespace widget_v1

// %% tags=["keep"]
namespace widget_v1 {
WidgetV1::~WidgetV1() = default;
}

// %% tags=["keep"]
void widget_v1::WidgetV1::PrintWidget() const { pImpl->PrintWidget(); }

// %% tags=["keep", "subslide"]
void widget_v1::WidgetV1::SetState(int state) { pImpl->SetState(state); }

// %% tags=["keep"]
int widget_v1::WidgetV1::GetState() const { return pImpl->GetState(); }
