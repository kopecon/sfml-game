//
// Created by Andrew on 26/12/2025.
//

#ifndef BONK_GAME_STATE_HPP
#define BONK_GAME_STATE_HPP

#include <functional>
#include <iostream>
#include <vector>


class Entity;

// THIS IS JUST AN ABSTRACT CLASS
template <typename States>
class State {
public:
    struct Edge {
        #pragma region constructors
        Edge() = default;
        explicit Edge(const States &next) : next(next) {}
        Edge(std::function<bool()> condition, const States &next) : next(next) {
            this->condition = std::move(condition);
        }
        #pragma endregion

        std::function<bool()> condition{};
        States next{};
    };

    #pragma region constructors
    virtual ~State() = default;

    explicit State(const States &stateID) : stateID(stateID) {}
    #pragma endregion

    // STATE IDENTITY
    States stateID{};  // Enum class representing possible states

    void addEdge(std::unique_ptr<Edge> edge) {
        edges.push_back(std::move(edge));
    }

    void addAction(std::function<void()> action) {
        // Actions are called in the order they were added in. FIFO.
        actions.push_back(std::move(action));
    }

    virtual void onEnter() {
        std::cout << " Entered state: " << static_cast<int>(stateID) << "\n";
    }
    virtual void onExit() {
        // std::cout << " Exited state: " << static_cast<int>(stateID) << "\n";
    }

    States next(const States &nextStateID) {
        // 0. Warn that state has no edges
        if (edges.empty()) std::cout << "State: " << static_cast<int>(stateID) << " has no edges!\n";
        // 1. Choose edge
        for (const auto &edge : this->edges) {
            // 1.a Edge has a specific condition -> resolve defined condition first
            if (edge->condition) {
                if (edge->condition() && nextStateID == edge->next) {
                    return edge->next;
                }
            }
            // 1.b Edge has no specific condition
            else {
                if (nextStateID == edge->next) {
                    return edge->next;
                }
            }
        }

        // 2. No edge conditions met. Staying in this state
        return this->stateID;
    }

    virtual void update() {
        for (auto const &action : actions) {
            if (actions.empty()) std::cout << "State: " << static_cast<int>(stateID) << " has no actions!\n";
            action();
        }
    };

private:
    std::vector<std::unique_ptr<Edge>> edges{};  // Connections to other states
    std::vector<std::function<void()>> actions{};  // Connections to other states
};

#endif //BONK_GAME_STATE_HPP