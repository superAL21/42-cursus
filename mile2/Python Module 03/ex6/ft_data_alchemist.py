#!/usr/bin/env python3

import random


def main():
    players = ['Alice', 'bob', 'Charlie', 'dylan',
               'Emma', 'Gregory', 'john', 'kevin', 'Liam']
    print(f"Initial list of players: {players}")
    capitalized_names = [_.capitalize() for _ in players]
    print(f"New list with all names capitalized: {capitalized_names}")
    only_capitalized = [name for name in players if name.istitle()]
    print(f"New list capitalized names only: {only_capitalized}\n")
    scores = {player: random.randint(1, 1000) for player in capitalized_names}
    print(f"Score dict: {scores}")
    average = sum(scores.values())/len(scores)
    print(f"Score average is {round(average, 2)}")
    high_scores = {player: scores[player]
                   for player in scores if scores[player] > average}
    print(f"High scores: {high_scores}")


if __name__ == "__main__":
    print("=== Game Data Alchemist ===\n")
    main()
