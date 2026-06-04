from ex0 import CreatureFactory, FlameFactory, AquaFactory


def test_factory(factory: CreatureFactory):
    try:
        print("Testing factory")
        base = factory.create_base()
        evol = factory.create_evolved()
        print(f"{base.describe()}")
        print(f"{base.attack()}")
        print(f"{evol.describe()}")
        print(f"{evol.attack()}")
        print("")
    except Exception as error:
        print(f"{error}")


def tes_battle(factory1: CreatureFactory, factory2: CreatureFactory):
    try:
        first_base = factory1.create_base()
        second_base = factory2.create_base()
        print("Testing battle")
        print(f"{first_base.describe()}")
        print(" vs.")
        print(f"{second_base.describe()}")
        print(" fight!")
        print(f"{first_base.attack()}")
        print(f"{second_base.attack()}")
    except Exception as error:
        print(f"{error}")


if __name__ == "__main__":
    test_factory(FlameFactory())
    test_factory(AquaFactory())
    tes_battle(FlameFactory(), AquaFactory())
