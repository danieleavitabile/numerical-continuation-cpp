CXX = g++ 
RM = rm -f
CPPFLAGS = -std=c++11 -g -O2
LDFLAGS = -std=c++11 -g -O2 -L/usr/local/lib -L/usr/lib
LDLIBS =  -larmadillo
INC =-I /usr/local/include/

SRCS = AbstractNonlinearProblem.cpp \
       AbstractNonlinearProblemJacobian.cpp \
       AbstractNonlinearSolver.cpp \
       NewtonSolver.cpp \
       ConvergenceCriterion.cpp \
       Fold.cpp \
       Driver.cpp

OBJS = $(subst .cpp,.o,$(SRCS))

all: Driver

Driver: $(OBJS) 
	$(CXX) $(LDFLAGS) -o Driver $(OBJS) $(LDLIBS) 

depend: .depend

.depend: $(SRCS)
	rm -f ./.depend
	$(CXX) $(CPPFLAGS) $(INC) -MM $^>>./.depend;

clean:
	$(RM) $(OBJS)

include .depend

