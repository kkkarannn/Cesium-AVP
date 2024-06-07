
# Trying to make Cesium for Unity to work for Apple Vision Pro 
Below is the log of the detailed steps we have followed 
### 1. Cloned cesium-unity-samples to start clean
### 2. Following [Cesium-Unity Developer Setup Guide](https://github.com/CesiumGS/cesium-unity/blob/main/Documentation~/developer-setup.md)
### 3. Following are the versions of Prerequisites libs

- cmake version 3.29.3
- dotnet version 6.0.423
- NASM version 2.16.03 compiled on Apr 17 2024
- JetBrains Rider 2024.1.1
- unity 2022.3.27f1 version with vision-pro setting
- Developing on Macbook pro M3 Max

### 3.1 Remove cesium plugin from package manager

### 3.2 Remove Cesium from scoped registry

### 4. Cloned the cesium-unity (plugin) project to com.cesium.unity folder:
```
cd cesium-unity-samples/Packages
git clone --recurse-submodules git@github.com:CesiumGS/cesium-unity.git com.cesium.unity
```

### 5. Ran this command
```dotnet publish Reinterop~ -o .```

### 6. Opened the project in unity editor 
***it is able to play and we did see the following error as mentioned in the developer setup guide***
DllNotFoundException: CesiumForUnityNative assembly:<unknown assembly> type:<unknown type> member:(null)
NotImplementedException: The native implementation is missing so OnValidate cannot be invoked.

did the folllowing steps to remediate 

```
cd cesium-unity-samples/Packages/com.cesium.unity/native~
cmake -B build -S . -DCMAKE_BUILD_TYPE=Debug
cmake --build build -j14 --target install --config Debug
```

### 7. Installed the following dependencies:
- com.unity.polyspatial 1.2.3
- com.unity.polyspatial.visionos 1.2.3
- com.unity.polyspatial.xr 1.2.3

### 8. While making the build, got the following error:
```
Win32Exception: ApplicationName='cmake', CommandLine='-B /Users/ashishgupta/dev/repos/cesium-unity-samples/Packages/com.cesium.unity/native~/build-VisionOS -S /Users/ashishgupta/dev/repos/cesium-unity-samples/Packages/com.cesium.unity/native~ -DEDITOR=false -DCMAKE_BUILD_TYPE=RelWithDebInfo -DCMAKE_INSTALL_PREFIX="/Users/ashishgupta/dev/repos/cesium-unity-samples/Packages/com.cesium.unity/Plugins/VisionOS" -DREINTEROP_GENERATED_DIRECTORY=generated-VisionOS', CurrentDirectory='/Users/ashishgupta/dev/repos/cesium-unity-samples/Packages/com.cesium.unity/native~', Native error= Cannot find the specified file 
```

Followed https://community.cesium.com/t/cmake-not-found-cesium-unity-for-visionos/32634/2?u=ashish-analog and made the changes in the following files:
CompileCesiumForUnityNative.cs
Cmake.cs

### 9. In the next step, Got error while building 
in /cesium-unity-abp/Packages/com.cesium.unity/native~/build-VisionOS/build.log File
```
/Users/ashishgupta/dev/repos/cesium-unity-samples/Packages/com.cesium.unity/native~/Shared/src/UnityAssetAccessor.cpp:8:10: fatal error: 'DotNet/CesiumForUnity/Helpers.h' file not found
#include <DotNet/CesiumForUnity/Helpers.h>
         ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
1 error generated.
1 error generated.
make[2]: *** [Runtime/CMakeFiles/CesiumForUnityNative-Runtime.dir/src/CesiumCreditSystemImpl.cpp.o] Error 1
make[2]: *** [Runtime/CMakeFiles/CesiumForUnityNative-Runtime.dir/__/Shared/src/UnityAssetAccessor.cpp.o] Error 1
In file included from /Users/ashishgupta/dev/repos/cesium-unity-samples/Packages/com.cesium.unity/native~/Runtime/src/CesiumFeatureImpl.cpp:1:
/Users/ashishgupta/dev/repos/cesium-unity-samples/Packages/com.cesium.unity/native~/Runtime/src/CesiumFeatureImpl.h:5:10: fatal error: 'DotNet/CesiumForUnity/CesiumMetadataValue.h' file not found
#include <DotNet/CesiumForUnity/CesiumMetadataValue.h>
         ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
1 error generated.
make[2]: *** [Runtime/CMakeFiles/CesiumForUnityNative-Runtime.dir/src/CesiumFeatureImpl.cpp.o] Error 1
/Users/ashishgupta/dev/repos/cesium-unity-samples/Packages/com.cesium.unity/native~/Runtime/src/CesiumFeatureIdAttributeImpl.cpp:3:10: fatal error: 'DotNet/CesiumForUnity/CesiumFeatureIdAttribute.h' file not found
#include <DotNet/CesiumForUnity/CesiumFeatureIdAttribute.h>
         ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
1 error generated.
make[2]: *** [Runtime/CMakeFiles/CesiumForUnityNative-Runtime.dir/src/CesiumFeatureIdAttributeImpl.cpp.o] Error 1
/Users/ashishgupta/dev/repos/cesium-unity-samples/Packages/com.cesium.unity/native~/Runtime/src/CesiumFeatureIdTextureImpl.cpp:6:10: fatal error: 'DotNet/CesiumForUnity/CesiumFeatureIdTexture.h' file not found
#include <DotNet/CesiumForUnity/CesiumFeatureIdTexture.h>
         ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
1 error generated.
make[2]: *** [Runtime/CMakeFiles/CesiumForUnityNative-Runtime.dir/src/CesiumFeatureIdTextureImpl.cpp.o] Error 1
In file included from /Users/ashishgupta/dev/repos/cesium-unity-samples/Packages/com.cesium.unity/native~/Runtime/src/CesiumIonServerHelper.cpp:3:
/Users/ashishgupta/dev/repos/cesium-unity-samples/Packages/com.cesium.unity/native~/Runtime/src/UnityTilesetExternals.h:5:10: fatal error: 'DotNet/CesiumForUnity/Cesium3DTileset.h' file not found
#include <DotNet/CesiumForUnity/Cesium3DTileset.h>
         ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
1 error generated.
make[2]: *** [Runtime/CMakeFiles/CesiumForUnityNative-Runtime.dir/src/CesiumIonServerHelper.cpp.o] Error 1
/Users/ashishgupta/dev/repos/cesium-unity-samples/Packages/com.cesium.unity/native~/Runtime/src/Cesium3DTileImpl.cpp:7:10: fatal error: 'DotNet/Unity/Mathematics/double4x4.h' file not found
#include <DotNet/Unity/Mathematics/double4x4.h>
         ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
1 error generated.
make[2]: *** [Runtime/CMakeFiles/CesiumForUnityNative-Runtime.dir/src/Cesium3DTileImpl.cpp.o] Error 1
make[1]: *** [Runtime/CMakeFiles/CesiumForUnityNative-Runtime.dir/all] Error 2

```

### 10. make the following changes in Editor/ConfigureReinterop.cs 

```
#elif UNITY_VISIONOS
        public const string CppOutputPath = "../native~/Editor/generated-visionOS";
```

and following changes in Runtime/ConfigureReinterop.cs file
```
#elif UNITY_VISIONOS
        public const string CppOutputPath = "../native~/Runtime/generated-visionOS";

```

### 11. After the above steps, dotnet/xxxx/xxx.h errors got resolved
Got the following error after xcode build:

```

DllNotFoundException: Unable to load DLL 'CesiumForUnityNative-Runtime'. Tried the load the following dynamic libraries: Unable to load dynamic library '/CesiumForUnityNative-Runtime' because of 'Failed to open the requested dynamic library (0x06000000) dlerror() = dlopen(/CesiumForUnityNative-Runtime, 0x0005): tried: '/CesiumForUnityNative-Runtime' (no such file)
  at Reinterop.ReinteropInitializer..cctor () [0x00000] in <00000000000000000000000000000000>:0 
  at CesiumForUnity.Cesium3DTileset.CreateImplementation () [0x00000] in <00000000000000000000000000000000>:0 
Rethrow as TypeInitializationException: The type initializer for 'Reinterop.ReinteropInitializer' threw an exception.
  at CesiumForUnity.Cesium3DTileset.CreateImplementation () [0x00000] in <00000000000000000000000000000000>:0 
 -->
```
