#CHATBOT WITH RULE-BASED RESPONSES
import random

# Define ANSI escape codes for text colors
GREEN = "\033[32m"
RED = "\033[31m"
RESET = "\033[0m"

def chatbot(user_input):
    """
    Chatbot with rule-based responses, enhanced with context awareness and error handling.
    Args:
        user_input (str): The user's input.
    Returns:
        str: The chatbot's response.
    """
    
    # Predefined rules and responses
    greetings = ["hello", "hi", "hey", "howdy"]
    farewell = ["bye", "goodbye", "see you later", "adios"]
    questions = ["how are you", "what's up", "how's it going", "how are you doing"]
    thanks = ["thank you", "thanks"]
    affirmatives = ["yes", "sure", "of course"]
    negatives = ["no", "not really", "not at all"]

    # Responses
    yes_responses = [
        "Okay, how can I assist you today?",
        "Got it! Let me know what you'd like.",
        "Understood. What would you like to talk about?",
        "Sure, how can I be of service?"
    ]
    no_responses = [
        "No problem! Is there anything else I can help you with?",
        "That's alright. Feel free to ask if anything comes up.",
        "That's okay. Perhaps you'd like to try asking a different question?",
        "No worries. Let me know if you change your mind."
    ]
    generic_responses = [
        "That's interesting! Tell me more about it.",
        "Hmm, I'm curious to learn more. Can you elaborate?",
        "That's fascinating. What are your thoughts on this?",
        "Got it. Is there anything else you'd like to discuss?",
        "Great to hear! Is there anything you'd like help with?",
        "Feel free to talk about anything else too. I'm here to listen."
    ]
    error_responses = [
        "Sorry, I'm not sure I understand. Could you rephrase that?",
        "I'm still learning and evolving. Can you try asking in a different way?",
        "That's an interesting question, but it's beyond my current capabilities. Perhaps I can help with something else?"
    ]

    # Convert user input to lowercase for case-insensitive matching
    user_input = user_input.lower()

    # Check user input against predefined rules
    if any(greet in user_input for greet in greetings):
        return random.choice(greetings) + "! " + random.choice(yes_responses)
    elif any(fare in user_input for fare in farewell):
        return f"{RED}Goodbye! Have a great day!{RESET}"
    elif any(q in user_input for q in questions):
        return f"{RED}I'm doing well, thank you for asking! How about you?{RESET}"
    elif any(t in user_input for t in thanks):
        return f"{RED}You're welcome! Let me know if you have any other questions.{RESET}"
    elif any(a in user_input for a in affirmatives):
        return random.choice(yes_responses)
    elif any(n in user_input for n in negatives):
        return random.choice(no_responses)
    else:
        # Handle potential errors and offer to learn
        return random.choice(error_responses) + f"{RED} Would you like to try asking something else?{RESET}"

# Example usage
while True:
    user_input = input(f"{GREEN}You: {RESET}")
    response = chatbot(user_input)
    print(f"{RED}Chatbot: {RESET}", response)
