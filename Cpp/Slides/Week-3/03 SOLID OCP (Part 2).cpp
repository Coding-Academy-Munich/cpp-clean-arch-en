// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//   <b>SOLID: OCP (Part 2)</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Academy Munich</div>
// <br/>
// <!-- 03 SOLID OCP (Part 2).cpp -->
// <!-- slides/module_500_solid_grasp/topic_340_solic_ocp_part2.cpp -->


// %% [markdown]
//
// ## Recap: OCP Violation
//
// <img src="img/movie_v0.svg" alt="MovieV0"
//      style="display:block;margin:auto;width:50%"/>

// %% [markdown]
//
// ## Solution Proposal 1: Inheritance
//
// <img src="img/movie_v2.svg" alt="MovieV2"
//      style="display:block;margin:auto;width:70%"/>

// %% [markdown]
//
// - OCP is satisfied
// - Large scope of inheritance
//   - Price computation is the most important thing about movies?
// - Only one-dimensional classification
// - No possibility to change pricing scheme

// %% [markdown]
//
// ## Solution Proposal 2: Strategy Pattern
//
// <img src="img/movie_v3.svg" alt="MovieV3"
//      style="display:block;margin:auto;width:80%"/>

// %% [markdown]
//
// - OCP is satisfied
// - Inheritance is limited to price computation
// - Multi-dimensional classification is easy
// - Pricing scheme can be changed at runtime

// %% [markdown]
//
// ## Implementation

// %%
#include <iostream>
#include <memory>
#include <string>
#include <vector>

// %%
class Movie;

// %%
class PricingStrategy {
public:
    virtual ~PricingStrategy() = default;
    virtual double ComputePrice(const Movie&) const = 0;
};

// %%
class RegularPriceStrategy : public PricingStrategy {
public:
    double ComputePrice(const Movie&) const override { return 4.99; }
};


// %%
class ChildrenPriceStrategy : public PricingStrategy {
public:
    double ComputePrice(const Movie&) const override { return 5.99; }
};

// %%
class NewReleasePriceStrategy : public PricingStrategy {
public:
    double ComputePrice(const Movie&) const override { return 6.99; }
};

// %%
class Movie {
public:
    Movie(std::string title, std::unique_ptr<PricingStrategy> pricing_strategy)
        : title_(std::move(title)), pricing_strategy_(std::move(pricing_strategy)) {}

    double ComputePrice() const { return pricing_strategy_->ComputePrice(*this); }

    void PrintInfo() const {
        std::cout << title_ << " costs " << ComputePrice() << std::endl;
    }

private:
    std::string title_;
    std::unique_ptr<PricingStrategy> pricing_strategy_;
};

// %%
std::vector<Movie> movies;
movies.emplace_back("Casablanca", std::make_unique<RegularPriceStrategy>());
movies.emplace_back("Shrek", std::make_unique<ChildrenPriceStrategy>());
movies.emplace_back("Brand New", std::make_unique<NewReleasePriceStrategy>());

// %%
for (const auto& movie : movies) {
    movie.PrintInfo();
}

// %% [markdown]
//
// ## Workshop: Transport Fare Calculation System
//
// In a modern city, there are various modes of transportation available –
// buses, subways, trains, boats, etc. Each of these transportation modes has
// its own fare calculation method. For instance, bus fares might be based on
// flat rates, subways might use distance-based rates, and boats might have
// premium rates for scenic routes.

// %% [markdown]
//
// You are given a rudimentary fare calculation system that determines the fare
// based on transportation type. Unfortunately, this system violates the OCP
// since it isn't open for extension without modification. Every time a new
// transportation mode needs to be added, the core system needs to be modified.
//
// Your task is to refactor the system to adhere to the OCP. More specifically,
// you'll remove the `switch` statement in the fare calculation logic. The goal
// is to make the system easily extendable, allowing new transportation types to
// be added without modifying the existing code.

// %%
#include <iostream>

// %%
enum class TransportType
{
    BUS,
    SUBWAY,
    TRAIN,
    BOAT
};

// %%
class Transport {
public:
    Transport(TransportType type) : type_(type) {}

    double CalculateFare(double distance) {
        switch (type_) {
        case TransportType::BUS: return 2.50; // flat rate
        case TransportType::SUBWAY:
            return 1.50 + (distance * 0.20); // base rate + per km
        case TransportType::TRAIN:
            return 5.00 + (distance * 0.15);    // base rate + per km
        case TransportType::BOAT: return 10.00; // premium rate
        default: return 0.0;
        }
    }

private:
    TransportType type_;
};


// %%
Transport bus(TransportType::BUS);
std::cout << "Bus fare: $" << bus.CalculateFare(10) << "\n";

// %%
Transport subway(TransportType::SUBWAY);
std::cout << "Subway fare: $" << subway.CalculateFare(10) << "\n";

// %%
Transport train(TransportType::TRAIN);
std::cout << "Train fare: $" << train.CalculateFare(10) << "\n";

// %%
Transport boat(TransportType::BOAT);
std::cout << "Boat fare: $" << boat.CalculateFare(10) << "\n";

// %%
#include <iostream>
#include <memory>

// %%
class FareCalculationStrategy {
public:
    FareCalculationStrategy() = default;
    FareCalculationStrategy(const FareCalculationStrategy&) = delete;
    FareCalculationStrategy& operator=(const FareCalculationStrategy&) = delete;
    FareCalculationStrategy(FareCalculationStrategy&&) = delete;
    FareCalculationStrategy& operator=(FareCalculationStrategy&&) = delete;
    virtual ~FareCalculationStrategy() = default;

    virtual double CalculateFare(double distance) = 0;
};

// %%
class BusFare : public FareCalculationStrategy {
public:
    double CalculateFare(double distance) override {
        return 2.50; // flat rate
    }
};

// %%
class SubwayFare : public FareCalculationStrategy {
public:
    double CalculateFare(double distance) override {
        return 1.50 + (distance * 0.20); // base rate + per km
    }
};

// %%
class TrainFare : public FareCalculationStrategy {
public:
    double CalculateFare(double distance) override {
        return 5.00 + (distance * 0.15); // base rate + per km
    }
};

// %%
class BoatFare : public FareCalculationStrategy {
public:
    double CalculateFare(double distance) override {
        return 10.00; // premium rate
    }
};

// %%
class Transport {
public:
    Transport(std::unique_ptr<FareCalculationStrategy> fareStrategy)
        : fareStrategy_{std::move(fareStrategy)} {}

    double ComputeFare(double distance) { return fareStrategy_->CalculateFare(distance); }

private:
    std::unique_ptr<FareCalculationStrategy> fareStrategy_;
};

// %%
Transport bus(std::make_unique<BusFare>());
std::cout << "Bus fare: $" << bus.ComputeFare(10) << "\n";

// %%
Transport subway(std::make_unique<SubwayFare>());
std::cout << "Subway fare: $" << subway.ComputeFare(10) << "\n";

// %%
Transport train(std::make_unique<TrainFare>());
std::cout << "Train fare: $" << train.ComputeFare(10) << "\n";

// %%
Transport boat(std::make_unique<BoatFare>());
std::cout << "Boat fare: $" << boat.ComputeFare(10) << "\n";


// %% [markdown]
//
// ## Extra Workshop: Smart Home Device Control System with Strategy
//
// In an earlier workshop we implemented a Smart Home Device Control System.
//
// Solve the OCP problem for this system with the Strategy pattern.

// %%
class DeviceStrategy {
public:
    virtual ~DeviceStrategy() = default;
    virtual void Control() = 0;
    virtual void GetStatus() const = 0;
};

// %%
#include <iostream>

// %%
class LightStrategy : public DeviceStrategy {
public:
    void Control() override { std::cout << "Light control\n"; }
    void GetStatus() const override { std::cout << "Light status\n"; }
};

// %%
class ThermostatStrategy : public DeviceStrategy {
public:
    void Control() override { std::cout << "Thermostat control\n"; }
    void GetStatus() const override { std::cout << "Thermostat status\n"; }
};

// %%
class SecurityCameraStrategy : public DeviceStrategy {
public:
    void Control() override { std::cout << "Security camera control\n"; }
    void GetStatus() const override { std::cout << "Security camera status\n"; }
};

// %%
class SmartLockStrategy : public DeviceStrategy {
public:
    void Control() override { std::cout << "Smart lock control\n"; }
    void GetStatus() const override { std::cout << "Smart lock status\n"; }
};

// %%
#include <memory>

// %%
class SmartHomeDevice {
public:
    SmartHomeDevice(std::unique_ptr<DeviceStrategy> strategy)
        : strategy_{std::move(strategy)} {}

    void Control() { strategy_->Control(); }
    void GetStatus() { strategy_->GetStatus(); }

private:
    std::unique_ptr<DeviceStrategy> strategy_;
};

// %%
#include <vector>

// %%
std::vector<SmartHomeDevice> devices;

// %%
devices.emplace_back(std::make_unique<LightStrategy>());
devices.emplace_back(std::make_unique<ThermostatStrategy>());
devices.emplace_back(std::make_unique<SecurityCameraStrategy>());
devices.emplace_back(std::make_unique<SmartLockStrategy>());

// %%
for (auto& device : devices) {
    device.Control();
    device.GetStatus();
}
