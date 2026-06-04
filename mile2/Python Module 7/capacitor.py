from ex1 import HealingCreatureFactory, TransformCreatureFactory
from ex1.healing_factory import HealCapability
from ex1.transform_factory import TransformCapability


def test_healing_capability(factory: HealingCreatureFactory):
    try:
        print("Testing Creature with healing capability")
        print(" base:")
        base = factory.create_base()
        evol = factory.create_evolved()
        print(f"{base.describe()}")
        print(f"{base.attack()}")
        if isinstance(base, HealCapability):
            print(f"{base.heal()}")
        print(" evolved:")
        print(f"{evol.describe()}")
        print(f"{evol.attack()}")
        if isinstance(evol, HealCapability):
            print(f"{evol.heal()}")
        print("")
    except Exception as error:
        print(f"{error}")


def test_transform_capability(factory: TransformCreatureFactory):
    try:
        print("Testing Creature with transform capability")
        print(" base:")
        base = factory.create_base()
        evol = factory.create_evolved()
        print(f"{base.describe()}")
        print(f"{base.attack()}")
        if isinstance(base, TransformCapability):
            print(f"{base.transform()}")
        print(f"{base.attack()}")
        if isinstance(base, TransformCapability):
            print(f"{base.revert()}")
        print(" evolved:")
        print(f"{evol.describe()}")
        print(f"{evol.attack()}")
        if isinstance(evol, TransformCapability):
            print(f"{evol.transform()}")
        print(f"{evol.attack()}")
        if isinstance(evol, TransformCapability):
            print(f"{evol.revert()}")
        print("")
    except Exception as error:
        print(f"{error}")


if __name__ == "__main__":
    test_healing_capability(HealingCreatureFactory())
    test_transform_capability(TransformCreatureFactory())
