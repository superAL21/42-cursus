#!/usr/bin/env Python3

from abc import ABC, abstractmethod
from typing import Any, Dict

class DataProcessor(ABC):
	
	def __init__(self) -> None:
		self._processed_data: Any = None

	@abstractmethod
	def validate(self, data: Any) -> bool:
		pass

	@abstractmethod
	def ingest(self, data: Any) -> None:
		pass

	def output(self) -> tuple[int, str]:
		return self._processed_data


class NumericProcessor(DataProcessor):
	pass

class TextProcessor(DataProcessor):
	pass

class LogProcessor(DataProcessor):
	pass