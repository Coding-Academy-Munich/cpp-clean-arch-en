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
// <!-- 06 SOLID OCP (Part 2).cpp -->
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

// %% [markdown]
//
// ## Extra Workshop: Smart Home Device Control System with Strategy
//
// In an earlier workshop we implemented a Smart Home Device Control System.
//
// Solve the OCP problem for this system with the Strategy pattern.

// %%
