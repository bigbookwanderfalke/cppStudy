
#include <pthread.h>
#include <iostream>

class TestThread {
	private:
		pthread_t t;
		int a;
	public:
		TestThread() {
		}

		~TestThread() {
			pthread_join(this->t, NULL);
		}

		void setData(int a) {
			this->a = a;
		}

		int getData() {
			return this->a;
		}

		static void *execute(void *arg) {
			std::cout << "Hello thread " << reinterpret_cast<TestThread*>(arg)->getData() << std::endl;
		}

		void startThread() {
			pthread_create(&(this->t), NULL, &TestThread::execute, this);
		}
};

int main()
{
	TestThread *t = new TestThread();
	t->setData(1);
	t->startThread();
	delete t;
	return 0;
}
