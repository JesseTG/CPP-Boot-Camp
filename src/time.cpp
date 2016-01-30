#include @\cppref{header/chrono}{<chrono>}@ 
#include <iostream> 
#include @\cppref{header/thread}{<thread>}@@\tikzmark{time_thread}@

using std::chrono::@\cppref{chrono/duration/duration_cast}{duration\_cast}@;@\tikzmark{time_cast}@
using std::chrono::@\cppref{chrono/duration#Helper_types}{milliseconds}@;@\tikzmark{time_duration}@
using std::chrono::@\cppref{chrono/system_clock}{system\_clock}@;@\tikzmark{time_clock}@
using std::cout;
using std::endl;
using std::this_thread::@\cppref{thread/sleep_for}{sleep\_for}@;

const int FPS = 60;

int main() {
  milliseconds ms_per_frame(1000 / FPS);@\tikzmark{time_ctor}@
  system_clock::time_point start = system_clock::now();

  for (int i = 0; i < 300; i++) {@\tikzmark{time_loop}@
    cout << "Frame #" << i << endl;
    sleep_for(ms_per_frame);
  }

  system_clock::time_point finish = system_clock::now();
  cout << "Elapsed time: " << duration_cast<milliseconds>(end - start).count() / 1000.0f << " seconds\n";
}