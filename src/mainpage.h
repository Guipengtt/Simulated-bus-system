#ifndef SRC_MAINPAGE_H_
#define SRC_MAINPAGE_H_
/*! \mainpage Overview
 *
 *
 * <h1> Introduction </h1>
 * <p>
 * 1. How to obtin this program: use git, git clone the repoistory with ssh. <br>
 * 2. How to compile: <br>
 * a: open terminal <br>
 * b: cd project/src <br>
 * c: make
 * 3. How to run simulation: <br>
 * a: run the server side: ./build/bin/vis_sim <port_number>. <br>
 * b: run client side: open brower, http://127.0.0.1:<port_number>/web_graphics/project.html
 * </p>
 * <h2>Discussion of concrete class and abstract class </h2>
 * <p>There are two way to implement bus factory class. One way is to implement <br>
 * a abstract class. Another way is to implement a concrete class. The abstract <br>
 * class can declare the function but not defined. The concrete class can declare <br>
 * and defined functions in the same time.
 * </p>
 * <p>The way which I used to implement the bus factory class is using concrete class. <br>
 * There are two methods in the bus factory, which are constructor and a function which <br>
 * can generate a random number. There are also other 3 new classes which I created in <br>
 * the src file, which are SmallBus, RegularBus and LargeBus. They are also concrete class, <br>
 * which includes constructor and overided Report function.</p>
 * <h3>The pros and cons of concrete class </h3>
 * \image html ConcreteBusFactory.png width=30% height=45%
 * <p> Pros: <br>
 * The concrete provide a mechanism for code reuse. This mechanism allows different <br>
 * inheriting classes to have completely different functions from other classes. This allows <br>
 * different inheritance classes to perform different functions. It also allows user to use basic <br>
 * functions. </p>
 * <p> Cons: <br>
 * Usrs must create special subclasses, if they want to use the special function from subclasses. <br>
 * The concrete class also have a problem that if the functions from the basic class are changed, <br>
 * then the functions which are overrided in subclasses will also been changed.<br>
 * I use concrete class for 3 reasons.<br>
 * First, I can easily modify it using concrete, override the basic class functions.<br>
 * Second, I can add as many functions as I want to the subclass without changing the basic class<br>
 * behavior.Third, I can add different functions for each different subclass, and the behavior <br>
 * between the subclasses does not affect each other.There are two sections in the bus_factory.h file,<br>
 * and in the public section, there is a BusFactory constructor. In the private part, there is the<br>
 * Size Gerneration function. This function randomly generates three integers for randomly generating<br>
 * small, regular, and large buses. In the src directory, there are three new subclasses of bus, small,<br>
 * regular, and large. Each subclass contains a constructor and a report function associated with it.</p>
 * <h3>The pros and cons of abstract class </h3>
 * \image html AbstractBusFactory.png width=30% height=45%
 * <p> Pros: <br>
 * The behaviors of function which be declared in the basic class will not be changed. The users can <br>
 * can easily modify functions from subclasses. </p>
 * <p> Cons: <br>
 * If new virtual functions are add into the basic class, the subclasses also have to define the functions <br>
 * which be delcared in the basic class.</p>
 *
 *
 * <h2> Designing and Implementing the Observer Pattern </h2>
 * <p>Define a one-to-many dependency relationship between objects. When the state of an object changes, all <br>
 * objects that depend on it are notified and automatically updated. Here, the changed object is called the observation
 * target, and the notified object is called the observer. An observation target can correspond to multiple observers, <br>
 * and there is no mutual connection between these observers. You can add and delete observers as needed. Making the <br>
 * system easier to expand. </p>
 *
 * <h3> The IObserver.h class </h3>
 * \image html Observer-pattern-class-diagram.png width=30% height=45%
 * <p> This is abstract class which give a general module of any kind of concrete observer class. For example, the BusWebObserver<br>
 * is a kind of concrete observer class. The IObserver class also provide a virtual function which is notify. It allows derived classes <br>
 * override this class in any form which bases on behaviors which they want to observe.</p>
 *
 * <h3> The IObservable.h class </h3>
 * <p> This is a subject class which provide a parttern for the subjects which are observered. For example, the bus.h class has been modified <br>
 * to a derived class. This class also provides three methods which can add, clear and update observers.
 *
 * <h3> The BusWebObserver class </h3>
 * Which is the concrete class of the IObserver class. Which give a specify implementation of the Notify function which is declared in the Observable <br>
 * Class
 *
 * <h3>Other functions </h3>
 * <p>AddListener function, it is defined in the visualization_simulator.cc file. This funcation is to add to call the RegisterListener function which be <br>
 * declared in the IObservable class. There are two parameters which are bus id point and observer point. It will go through the busses_ vector, if the id_ <br>
 * matched to the bus id which in the buses_ vector. It will call the RegisterListener class. Finally, the observers which be passed into the RegisterListener class
 * will be assigned into the observer_ vector.
 * <br>
 * ClearListeners function, it will clean all the listeners which in the observers_ vectors.
 * </p>
 * <h3> Important resources to understand observer pattern </h3>
 * <p>https://www.tutorialspoint.com/design_pattern/observer_pattern.htm<br>
 *    https://en.wikipedia.org/wiki/Observer_pattern <br>
 *    https://www.geeksforgeeks.org/observer-pattern-set-1-introduction/ </p>
 */

#endif  // SRC_MAINPAGE_H_
