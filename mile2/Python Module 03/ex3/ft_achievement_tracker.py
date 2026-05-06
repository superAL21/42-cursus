#!/usr/bin/env python3

import random


def gen_player_achievements() -> set:
    achievements = ['Crafting Genius', 'Strategist', 'World Savior',
                    'Speed Runner', 'Survivor', 'Master Explorer',
                    'Treasure Hunter', 'Unstoppable', 'First Steps',
                    'Collector Supreme', 'Untouchable', 'Sharp Mind',
                    'Boss Slayer']
    number_rand = random.randint(4, len(achievements))
    player = random.sample(achievements, k=number_rand)
    return set(player)


def main() -> None:
    p_Alice = gen_player_achievements()
    print(f"Player Alice: {p_Alice}")
    p_Bob = gen_player_achievements()
    print(f"Player Bob: {p_Bob}")
    p_Charlie = gen_player_achievements()
    print(f"Player Charlie: {p_Charlie}")
    p_Dylan = gen_player_achievements()
    print(f"Player Dylan: {p_Dylan}")
    print()
    union = p_Alice.union(p_Bob, p_Charlie, p_Dylan)
    intersection = p_Alice.intersection(p_Bob, p_Charlie, p_Dylan)
    print(f"All distinct achievements: {union}\n")
    print(f"Common achievements: {intersection}\n")

    print(f"Only Alice has: {p_Alice.difference(p_Bob, p_Charlie, p_Dylan)}")
    print(f"Only Bob has: {p_Bob.difference(p_Alice, p_Charlie, p_Dylan)}")
    print(f"Only Charlie has: {p_Charlie.difference(p_Alice, p_Bob, p_Dylan)}")
    print(f"Only Dylan has: {p_Dylan.difference(p_Alice, p_Bob, p_Charlie)}")
    print()
    print(f"Alice is missing: {union.difference(p_Alice)}")
    print(f"Bob is missing: {union.difference(p_Bob)}")
    print(f"Charlie is missing: {union.difference(p_Charlie)}")
    print(f"Dylan is missing: {union.difference(p_Dylan)}")


if __name__ == "__main__":
    print("=== Achievement Tracker System ===\n")
    main()
