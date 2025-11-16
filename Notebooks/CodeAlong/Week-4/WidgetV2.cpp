#include "WidgetV2.h"

#include <iostream>

// %% tags=["keep", "subslide"]
class widget_v2::WidgetV2::Impl {
public:
    void PrintWidget() const {
        std::cout << "Impl::PrintWidget() const: " << state_ << "\n";
    }

    void PrintWidget() { std::cout << "Impl::PrintWidget(): " << state_ << "\n"; }

    int GetState() const {
        std::cout << "<Impl::GetState() const -> " << state_ << "> ";
        return state_;
    }

    int& GetState() {
        std::cout << "<Impl::GetState() -> " << state_ << "> ";
        return state_;
    }

    void SetState(int state) { state_ = state; }

private:
    int state_{};
};

// %% tags=["keep", "subslide"]
namespace widget_v2 {
WidgetV2::WidgetV2() : pImpl{std::make_unique<Impl>()} {}
} // namespace widget_v2

// %% tags=["keep"]
namespace widget_v2 {
WidgetV2::~WidgetV2() = default;
}

// %% tags=["keep"]
void widget_v2::WidgetV2::PrintWidget() const { pImpl->PrintWidget(); }

// %% tags=["keep", "subslide"]
void widget_v2::WidgetV2::SetState(int state) { pImpl->SetState(state); }

// %% tags=["keep"]
int widget_v2::WidgetV2::GetState() const { return pImpl->GetState(); }

// %% tags=["keep"]
int& widget_v2::WidgetV2::GetState() { return pImpl->GetState(); }
