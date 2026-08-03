from llm_sdk import Small_LLM_Model
from typing import Any


class Wrapper_LLM():
    def __init__(self, model: Small_LLM_Model):
        self.model = model

    def generate(
        self, prompt: str,
        functions_def: list[dict[str, Any]],
        max_tokens: int) -> dict[str, Any]:
        full_prompt = f"""
        You are a function-calling model.
        Return ONLY valid JSON.
        Do not write explanations.

        Allowed function names:
        {[f["name"] for f in functions_def]}

        User prompt:
        {prompt}

        Output format (exact keys):
        {{
            "name": "<allowed function name>",
            "parameters": {{}}
        }}
        """
        actual_context = self.model.encode(full_prompt)
        generated_tokens = []
        return {"name": "debug", "parameters":{}}
