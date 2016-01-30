//
// Pool.cpp for  in /home/soidik_d/Semestre_05/cpp/rtype/vendors/thread
// 
// Made by SOIDIKI Djamil
// Login   <soidik_d@epitech.net>
// 
// Started on  Sun Dec  6 19:20:18 2015 SOIDIKI Djamil
// Last update Sat Jan  2 17:55:34 2016 SOIDIKI Djamil
//

#include	"Pool.hh"

using namespace Thread::Pattern;

void*		start_routine(void* arg)
{
  Thread::Pattern::Pool* threadpool = 
    reinterpret_cast<Thread::Pattern::Pool*>(arg);
  
  threadpool->routine(NULL);
  return (NULL);
}

Pool::Pool(int threads, Server* server) : _state(RUNNING), _server(server)
{
  int		i = -1;

  this->_mutex.init();
  this->_condition.init();

  while (++i < threads)
    {
      Thread::UThread		thread(this->_workers.size() + 1);
      
      thread.create(&start_routine, this);
      this->_workers.emplace_back(thread);
    }
}

Pool::~Pool()
{
  {
    this->_mutex.lock();
    this->_state = STOP;
  }

  std::vector<Thread::UThread>::iterator it = this->_workers.begin();
  
  while (it != this->_workers.end())
    {
      (*it).join();
      ++it;
    }
}

void		Pool::enqueue(Packet f)
{
  {
    this->_mutex.lock();
    this->_tasks.push(f);
    this->_mutex.unlock();
  }

  this->_condition.signal();
}

void*		Pool::routine(void* arg)
{
  Packet	task;

  (void) arg;
  while (true)
    {
      {
	this->_mutex.lock();
	this->_condition.wait(this->_mutex.getMutex());
	
	if (this->_state == STOP || this->_tasks.empty())
	  break;
	
	task = this->_tasks.front();
	this->_tasks.pop();
	
	this->_mutex.unlock();
      }
      this->_mutex.lock();
      std::cout << "Bytes reçu: " << task.getBytes() << std::endl;
      this->_mutex.unlock();
    }
  return (NULL);
}
