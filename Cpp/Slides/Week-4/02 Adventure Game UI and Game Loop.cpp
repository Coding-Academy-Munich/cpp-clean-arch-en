// -*- coding: utf-8 -*-
// %% [markdown]
//
// <div style="text-align:center; font-size:200%;">
//   <b>Adventure Game: UI and Game Loop</b>
// </div>
// <br/>
// <div style="text-align:center; font-size:120%;">Dr. Matthias Hölzl</div>
// <br/>
// <div style="text-align:center;">Coding-Academy Munich</div>
// <br/>
// <!-- 02 Adventure Game UI and Game Loop.cpp -->
// <!-- slides/module_500_solid_grasp/topic_450_adventure_observer.cpp -->
//
// <!--
// clang-format off
// -->

// %% [markdown]
//
// - OCP with Strategy Pattern
// - Observer to decouple concrete UI

// %% [markdown]
//
// - Version 5b `Player.cpp`:
//
// ```cpp
// std::vector<ActionPtr> Player::GetPossibleActions() const
// {
//     std::vector<ActionPtr> result {};
//     // Fill `result` with all possible actions
//     if (!IsInteractive()) {
//         std::cout << "Possible actions:\n";
//         for (const auto& action : result) {
//             std::cout << "  " << action->Description() << '\n';
//         }
//     }
//     return result;
// }
// ```

// %% [markdown]
//
// - Version 5c `Player.cpp`:
//
// ```cpp
// std::vector<ActionPtr> Player::GetPossibleActions() const
// {
//     std::vector<ActionPtr> result {};
//     // Fill `result` with all possible actions
//     NotePossibleActions(result); // <-- Notify observers
//     return result;
// }
// ```

// %% [markdown]
//
// `code/completed/adventure/v5b/lib/Player.cpp`
//
// `code/completed/adventure/v5c/lib/Player.cpp`

// %% [markdown]
//
// ## Conclusion
//
// - We now have a lot of flexibility when implementing player behavior
// - We are completely decoupled from the concrete implementation of the UI
// - For users, it is not particularly easy to configure and start a game

// %% [markdown]
//
// - Version 5c `main.cpp`:
//
// ```cpp
// int main(int argc, const char* argv[])
// {
//     World world {WorldFactory::create(dungeonLocationDataVector)};
//     std::unique_ptr<SelectActionStrategy> strategy {};
//     // Choose strategy from command line arguments (create unique_ptr<...>)
//
//     Player player {"Test Player", world.GetInitialLocation(), std::move(strategy)};
//     std::shared_ptr<PlayerObserver> observer {std::make_shared<CliPlayerObserver>()};
//     player.RegisterObserver(observer);
//
//     // Main Loop:
//     try {
//         for (int i {}; i < 10; ++i) {
//             std::cout << "Turn " << i + 1 << ": Player [" << player << "]\n";
//             player.TakeTurn();
//         }
//     } catch (const QuitGameException&) {
//         std::cout << "Goodbye!\n";
//     } catch (const std::exception& e) {
//         std::cout << "Error: " << e.what() << '\n';
//     }
//     return 0;
// }
// ```

// %% [markdown]
//
// - We want to simplify the interface for users of our library
// - The GRASP pattern *Controller* is suitable for this

// %% [markdown]
//
// - Version 6a `main.cpp`:
//
// ```cpp
// int main(int argc, const char* argv[]) {
//    std::string strategyOption {"random"};
//    // Choose strategy (as string) from command line arguments
//
//    Game game {dungeonLocationDataVector, std::make_shared<CliGameObserver>()};
//    game.AddPlayer("Test Player", strategyOption);
//    game.Run();
//
//    return 0;
// }
// ```
