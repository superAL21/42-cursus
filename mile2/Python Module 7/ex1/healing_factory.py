from ex0.creatures import Creature
from ex0.factory import CreatureFactory
from .capabilities import HealCapability


class HealingCreatureFactory(CreatureFactory):
    def create_base(self) -> Creature:
        return Sproutling()

    def create_evolved(self) -> Creature:
        return Bloomelle()


class Sproutling(Creature, HealCapability):
    def __init__(self):
        Creature.__init__(self, "Sproutling", "Grass")

    def heal(self) -> str:
        return f"{self._name} heals itself for a small amount"

    def attack(self) -> str:
        return f"{self._name} uses Vine Whip!"


class Bloomelle(Creature, HealCapability):
    def __init__(self):
        Creature.__init__(self, "Bloomelle", "Grass/Fairy")

    def heal(self) -> str:
        return f"{self._name} heals itself and others for a large amount"

    def attack(self) -> str:
        return f"{self._name} uses Petal Dance!"
