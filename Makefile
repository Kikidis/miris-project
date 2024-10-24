# Ορισμός του compiler
CXX = g++

# Ορισμός των flags για το compile (π.χ., -Wall για εμφάνιση όλων των warnings)
CXXFLAGS = -Wall -std=c++11

# Το όνομα του τελικού εκτελέσιμου αρχείου
TARGET = miris

# Τα αρχεία πηγαίου κώδικα (.cpp) που χρησιμοποιούνται
SRCS = GraphComponents.cpp Graph.cpp Demo.cpp
HEADERS = GraphComponents.h Graph.h Demo.h # Το αρχείο .h που θέλουμε να παρακολουθούμε

# Τα αρχεία αντικειμένων (.o) που θα παραχθούν από το compile
OBJS = $(SRCS:.cpp=.o)

# Ορισμός του τι θα κάνει το make
all: $(TARGET)

# Ορισμός της διαδικασίας δημιουργίας του εκτελέσιμου αρχείου
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Κανόνας για το πως να κάνει compile κάθε .cpp αρχείο σε .o αρχείο
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Εκτέλεση του προγράμματος
run: $(TARGET)
	./$(TARGET)

# Καθαρισμός των παραγόμενων αρχείων
clean:
	rm -f $(OBJS) $(TARGET)
