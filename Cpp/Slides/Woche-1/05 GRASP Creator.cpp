// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//   <b>GRASP: Creator</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Academy Munich</div>
// <br/>
// <!-- 05 GRASP Creator.cpp -->
// <!-- slides/module_500_solid_grasp/topic_160_grasp_creator.cpp -->


// %% [markdown]
//
// - Use Case "Initialize the Game"
// - So far:
//   - `World` and `Location` classes
//   - Attributes and getters
// - Question:
//   - Who creates the `Location` instances?

// %% [markdown]
//
// ## Candidates

// %% [markdown]
// <div style="float:left;margin:auto;padding:80px 0;width:25%">
// <ul>
// <li> <code>Player</code></li>
// <li> <code>Game</code></li>
// <li> <code>Pawn</code></li>
// <li> <code>World</code></li>
// </ul>
// </div>
// <img src="img/adv-domain-03-small.svg"
//      style="float:right;margin:auto;width:70%"/>

// %% [markdown]
//
// ## The Creator Pattern (GRASP)
//
// ### Question
//
// Who creates an object?
//
// ### Answer
//
// Assign class `A` the responsibility to create an instance of `B` if one or
// more of the following apply:
//
// - `A` contains or owns `B`
// - `A` records `B` (e.g., stores it in a database)
// - `A` closely uses `B`
// - `A` has the initializing data that `B` requires

// %% [markdown]
//
// ### Remark
//
// - Factory is often an alternative to Creator

// %% [markdown]
//
// ## Creator

// %% [markdown]
// <div style="float:left;margin:auto;padding:80px 0;width:25%">
// <ul>
// <li> <strike><code>Player</code></strike></li>
// <li> <strike><code>Game</code></strike></li>
// <li> <code>Pawn</code></li>
// <li> <b><code>World</code></b></li>
// </ul>
// </div>
// <img src="img/adv-domain-03-small.svg"
//      style="float:right;margin:auto;width:70%"/>


// %% [markdown]
// ```cpp
// class World {
// public:
//     World(const std::vector<LocationData>& locationData,
//         std::string initialLocationName);
//
//     explicit World(const std::vector<data::LocationData>& locationData);
//
//     const std::unordered_map<std::string, Location>& GetLocations() const;
//     const std::string& GetInitialLocationName() const;
//
// private:
//     std::unordered_map<std::string, Location> locations;
//     std::string initialLocationName;
// };
// ```

// %% [markdown]
// ```cpp
// World::World(const std::vector<LocationData>& locationData, std::string initialLocationName)
//     : locations {}
//     , initialLocationName { std::move(initialLocationName) }
// {
//     locations.reserve(locationData.size());
//     for (const auto& location : locationData) {
//         locations.emplace(location.name, location);
//     }
// }
// ```

// %%
// ```cpp
// World::World(const std::vector<data::LocationData>& locationData)
//     : World {locationData, locationData[0].name}
// {}
// ```


// %% [markdown]
//
// - We can adapt the `main()` method to use the `World` class.

// %% [markdown]
// ```cpp
// using namespace adventure_sk;
// ```

// %%
// ```cpp
// int main()
// {
//     World world{World(data::simpleLocations)};
//     std::cout << world << '\n';
//     for (const auto& [name, location] : world.GetLocations()) {
//         std::cout << location << '\n';
//     }

//     return 0;
// }
// ```
