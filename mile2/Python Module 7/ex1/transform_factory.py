from ex0.creatures import Creature
from ex0.factory import CreatureFactory
from .capabilities import TransformCapability


class TransformCreatureFactory(CreatureFactory):
    def create_base(self) -> Creature:
        return Shiftling()

    def create_evolved(self) -> Creature:
        return Morphagon()


class Shiftling(Creature, TransformCapability):
    def __init__(self):
        Creature.__init__(self, "Shiftling", "Normal")
        TransformCapability.__init__(self)

    def attack(self) -> str:
        if self._is_transformed:
            return f"{self._name} performs a boosted strike!"
        return f"{self._name} attacks normally."

    def transform(self) -> str:
        if not self._is_transformed:
            self._is_transformed = True
            return f"{self._name} shifts into a sharper form!"
        return f"{self._name} is already transformed!"

    def revert(self) -> str:
        if self._is_transformed:
            self._is_transformed = False
            return f"{self._name} returns to normal."
        return f"{self._name} is already in base form!"


class Morphagon(Creature, TransformCapability):
    def __init__(self):
        Creature.__init__(self, "Morphagon", "Normal/Dragon")
        TransformCapability.__init__(self)

    def attack(self) -> str:
        if not self._is_transformed:
            return f"{self._name} attacks normally."
        return f"{self._name} unleashes a devasting morph strike!"

    def transform(self) -> str:
        if not self._is_transformed:
            self._is_transformed = True
            return f"{self._name} morphs into a dragonic battle form!"
        return f"{self._name} is already transformed!"

    def revert(self):
        if self._is_transformed:
            self._is_transformed = False
            return f"{self._name} stabilizes its form."
        return f"{self._name} is already in base form!"
