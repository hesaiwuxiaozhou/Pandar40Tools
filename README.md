# Pandar40Tools
This project provide the following functions:
```
1. Lidar data parser of Pandar40.
2. Convertion of Intensity in Lidar data to RGB .
```

# Usage
Indepentantly:
```
cd Pandar40Tools
mkdir build ; cd build ; cmake ..
make
```
You can run the testing tools.

Embed to your project:
1. add following cmake code to your CMakeLists.txt:
```
add_subdirectory(Pandar40Tools)
...
target_link_libraries(${your_project}
	Pandar40Tools
)
```

2. Use Pandar40Tools in your c/c++ project:
```
#include "LidarTools.h"
...
```
After that, you can invoke all the tools in Pandar40Tools.

# Lience
Totally free!!!
