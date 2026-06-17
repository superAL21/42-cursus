from enum import Enum
from pydantic import BaseModel, Field, ValidationError, model_validator
from datetime import datetime
from typing import Optional


class ContactType(str, Enum):
    RADIO = "radio"
    VISUAL = "visual"
    PHYSICAL = "physical"
    TELEPATHIC = "telepathic"


class AlienContact(BaseModel):
    contact_id: str = Field(min_length=5, max_length=15)
    timestamp: datetime
    location: str = Field(min_length=3, max_length=100)
    contact_type: ContactType
    signal_strength: float = Field(ge=0.0, le=10.0)
    duration_minutes: int = Field(ge=1, le=1440)
    witness_count: int = Field(ge=1, le=100)
    message_received: Optional[str] = Field(default=None, max_length=500)
    is_verified: bool = Field(default=False)

    @model_validator(mode="after")
    def validation_rules(self) -> "AlienContact":
        if not self.contact_id.startswith("AC"):
            raise ValueError("Contact ID must start with 'AC'")

        if self.contact_type == ContactType.PHYSICAL and not self.is_verified:
            raise ValueError("Physical contact reports must be verified")

        if (
            self.contact_type == ContactType.TELEPATHIC
            and self.witness_count < 3
        ):
            raise ValueError(
                "Telepathic contact requires at least 3 witnesses"
                )

        if self.signal_strength > 7.0 and not self.message_received:
            raise ValueError("Strong signals should include received messages")

        return self


def main():
    print("Alien Contact Log Validation")
    print("======================================")

    alien_contact = AlienContact(
        contact_id='AC_2024_001',
        timestamp=datetime(2024, 1, 20, 0, 0, 0),
        location='Atacama Desert, Chile',
        contact_type=ContactType.VISUAL,
        signal_strength=9.6,
        duration_minutes=99,
        witness_count=11,
        message_received='Greetings from Zeta Reticuli',
        is_verified=False
    )
    print("Valid contact report:")
    print(f"ID: {alien_contact.contact_id}")
    print(f"Type: {alien_contact.contact_type.value}")
    print(f"Location: {alien_contact.location}")
    print(f"Signal: {alien_contact.signal_strength}/10")
    print(f"Duration: {alien_contact.duration_minutes} minutes")
    print(f"Witnesses: {alien_contact.witness_count}")
    print(f"Message: '{alien_contact.message_received}'")

    print("\n======================================")
    print("Expected validation error:")
    try:
        invalid_contact = AlienContact(
            contact_id='AC_2024_003',
            timestamp=datetime(2024, 11, 15, 0, 0, 0),
            location='Very Large Array, New Mexico',
            contact_type=ContactType.TELEPATHIC,
            signal_strength=4.5,
            duration_minutes=19,
            witness_count=2,
            message_received=None,
            is_verified=False
        )
        print(f"{invalid_contact}")

    except ValidationError as error:
        print(f"{error.errors()[0]['msg'].removeprefix("Value error, ")}")


if __name__ == "__main__":
    main()
