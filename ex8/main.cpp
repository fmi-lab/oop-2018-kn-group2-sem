#include <iostream>
using namespace std;

template <typename T>
struct Input {
	int id;
	T data;
};

template <typename T>
struct State {
	int id;
	T data;
};

template <typename T, typename I>
struct Transition {
	State<T> fromState;
	Input<I> input;
	State<T> toState;
};

template <typename T, typename I>
class FSMConfig {};


template <typename T, typename I>
class FSM;


template <typename T, typename I>
class FSMBuilder {
public:
	FSM<T, I> build();
private:
	FSMConfig<T, I> config;
	State<T> initialState;
};


template <typename T, typename I>
class FSM {
public:
	void print() {
		// cout << currentState << endl;
	}
private:
	// private constructor
	FSM(FSMConfig<T, I> config, State<T> currentState) {
		this->config = config;
		this->currentState = currentState;
	}
private:
	FSMConfig<T, I> config;
	State<T> currentState;

	friend class FSMBuilder<T, I>;
};

template <typename T, typename I>
FSM<T, I> FSMBuilder<T, I>::build() {
	return FSM<T, I>(config, initialState);
}

int main() {
	FSM<char, int> fsm = FSMBuilder<char, int>().build(); // 42
	fsm.print();
	return 0;
}
