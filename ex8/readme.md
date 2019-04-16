Упражнение 8
===

FSM
Finite State Machine

// method chaining
FSM()
	.setInitilState(State())
	.setErrorState(State())
	.addFinalState(State())
	.addFinalState(State())
	.addFinalState(State())
	.addTransition(State(), Input(), State())
	.addTransition(State(), Input(), State())
