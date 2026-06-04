from ex0.factory import FlameFactory, AquaFactory
from ex1.healing_factory import HealingCreatureFactory
from ex1.transform_factory import TransformCreatureFactory
from ex2.battle_strategies import (
    NormalStrategy,
    DefensiveStrategy,
    AggressiveStrategy,
    InvalidStrategyError
)


def battle(name: str, info_data: str, opponents: list):
    print(f"Tournament {name}")
    print(f"{info_data}")
    print("*** Tournament ***")
    print(f"{len(opponents)} opponents involved")

    for i in range(len(opponents)):
        for j in range(i + 1, len(opponents)):
            c1, s1 = opponents[i]
            c2, s2 = opponents[j]
            print("\n* Battle *")
            print(f"{c1.describe()}")
            print(" vs.")
            print(f"{c2.describe()}")
            print(" now fight!")
            try:
                print(f"{s1.act(c1)}")
                print(f"{s2.act(c2)}")
            except InvalidStrategyError as error:
                print(f"Battle error, aborting tournament: {error}")
                return


if __name__ == "__main__":
    flame_factory = FlameFactory()
    aqua_factory = AquaFactory()
    healing_factory = HealingCreatureFactory()
    transform_factory = TransformCreatureFactory()

    opponents_0 = [
        (flame_factory.create_base(),
         NormalStrategy()),
        (healing_factory.create_base(),
         DefensiveStrategy())]
    battle(
        "0 (basic)",
        "[ (Flameling+Normal), (Healing+Defensive) ]",
        opponents_0
        )

    print("")

    opponents_1 = [
        (flame_factory.create_base(),
         AggressiveStrategy()),
        (healing_factory.create_base(),
         DefensiveStrategy())
    ]
    battle(
        "1 (error)",
        "[ (Flameling+Aggressive), (Healing+Defensive) ]",
        opponents_1
        )

    print("")

    opponents_2 = [
        (aqua_factory.create_base(),
         NormalStrategy()),
        (healing_factory.create_base(),
         DefensiveStrategy()),
        (transform_factory.create_base(),
         AggressiveStrategy())
    ]
    battle(
        "2 (multiple)",
        "[ (Aquabub+Normal), (Healing+Defensive), (Transform+Aggressive) ]",
        opponents_2
        )
