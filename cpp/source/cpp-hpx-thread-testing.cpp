#include <hpx/hpx_main.hpp>
#include <hpx/hpx.hpp>

#include <functional>

void foo()
{
	return;
}

void hpx_thread_test_function_ptr()
{
	hpx::thread t1 {&foo};
	t1.join();
}

void hpx_thread_test_lambda()
{
	hpx::thread t1 {[]() {return;}};
	t1.join();
}

void hpx_async_test_function_ptr()
{
	hpx::lcos::future<void> f1 = hpx::async(&foo);
	f1.get();
}

void hpx_async_test_lambda()
{
	hpx::lcos::future<void> f1 = hpx::async([](){return;});
	f1.wait();
}

int main()
{
	hpx_async_test_function_ptr();
	hpx_async_test_lambda();
	hpx_thread_test_function_ptr();
	hpx_thread_test_lambda();
}
