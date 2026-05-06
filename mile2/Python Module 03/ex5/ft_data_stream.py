#!/usr/bin/env python3

from typing import Generator
import random


def gen_event() -> Generator[tuple]:
    list_of_players = ["Alice", "Bob", "Charlie", "Dylan"]
    actions = ["run", "eat", "sleep", "grab",
               "move", "climb", "swim"]

    while True:
        player = random.choice(list_of_players)
        action = random.choice(actions)
        yield (player, action)


def consume_event(list_of_ten: list) -> Generator[tuple]:
    while list_of_ten:
        element = random.randrange(len(list_of_ten))
        event = list_of_ten.pop(element)
        yield event


if __name__ == "__main__":
    my_game = gen_event()
    for i in range(0, 1000):
        player, action = next(my_game)
        print(f"Event {i}: Player {player} did action {action}")

    generator_ten_events = gen_event()

    list_ten_events: list[tuple] = []

    for i in range(10):
        element = next(generator_ten_events)
        list_ten_events.append(element)
    print(f"Built list of 10 events: {list_ten_events}")

    consume = consume_event(list_ten_events)

    while True:
        try:
            event = next(consume)
            print(f"Got event from list: {event}")
            print(f"Remains in list: {list_ten_events}")
        except StopIteration:
            break
