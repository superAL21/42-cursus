#!/usr/bin/env python3

import sys


def main() -> None:
    print("=== Player Score Analytics ===")

    if len(sys.argv) <= 1:
        print("No scores provided. Usage: python3 "
              "ft_score_analytics.py <score1> <score2> ...\n")
        return

    scores: list[int] = []

    for arg in sys.argv[1:]:
        try:
            value = int(arg)
            scores.append(value)
        except ValueError:
            print(f"Invalid parameter: '{arg}'")
    if len(scores) >= 1:
        print(f"Scores processed: {scores}")
        print(f"Total players: {len(scores)}")
        print(f"Total score: {sum(scores)}")
        print(f"Average score: {sum(scores) / len(scores)}")
        print(f"High score: {max(scores)}")
        print(f"Low score: {min(scores)}")
        print(f"Score range: {max(scores) - min(scores)}\n")

    else:
        print("No scores provided. Usage: python3 "
              "ft_score_analytics.py <score1> <score2> ...")
        return


if __name__ == "__main__":
    main()
