[![Contributors][contributors-shield]][contributors-url]
[![Forks][forks-shield]][forks-url]
[![Stargazers][stars-shield]][stars-url]
[![MIT][license-shield]][license-url]



<!-- PROJECT LOGO -->
<br />
<div align="center">
<h3 align="center">OpenGL Compute Shader Raytracer Demo</h3>

  <p align="center">
    Not much else to say lol 
    <br />
  </p>
</div>


<!-- ABOUT THE PROJECT -->
## About The Project
Implementation of [Raytracing in a weekend](https://raytracing.github.io/books/RayTracingInOneWeekend.html)  
Old Raytracing project of mine, combined with **a lot** of unfinished frameworks I had been building/using  
Most of the code written here ended up in my premake5-workspace-template project on the with-subprojects branch
Migrated the latest branch ```WIP_RaytracerScene``` to the template workspace


### Project Structure
Same as my template project, **[premake5-workspace-template](https://github.com/inonitz/premake5-workspace-template)**


### Built With
<br> [<img height="100px" src="https://raw.githubusercontent.com/cginternals/glbinding/master/glbinding-logo.svg?sanitize=true">][glbinding-url] </br>
<br> 
  [![GLFW v3.4][GLFW.js]][GLFW-url]&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
  [![ImGui][ImGui.js]][ImGui-url] 
</br>

<!-- GETTING STARTED -->
## Getting Started

### Prerequisites
* [premake](https://premake.github.io/docs/) 
* Working compiler toolchain, preferably clang
  * Windows: You should use [llvm](https://github.com/llvm/llvm-project/releases)
  * Linux:
      1. [installing-specific-llvm-version](https://askubuntu.com/questions/1508260/how-do-i-install-clang-18-on-ubuntu)
      2. [configuring-symlinks](https://unix.stackexchange.com/questions/596226/how-to-change-clang-10-llvm-10-etc-to-clang-llvm-etc)
  * Define these environment variables (in your PATH):
    * LLVMInstallDir
    * LLVMToolsVersion
* Powershell / Any Standard unix-shell **(If you're compiling an executable)**

### Installation
```sh
git clone -b updatedRayTracer https://github.com/inonitz/glsl-compute-raytracer.git
# Don't forget to add your own remote repo
git remote set-url origin your_github_username/glsl-compute-raytracer
git remote -v
```

<!-- USAGE EXAMPLES -->
## Usage

call ```premake5 help``` in the cloned repo directory ```(.vscode/..)```

### Common Commands:
```sh
    premake5 --proj=program cleanproj 
    premake cleanall 
    premake cleancfgs
    premake cleanclangd
    premake export-compile-commands
    premake --os=windows --arch=x86_64 --cc=clang gmake2
    premake --os=windows --arch=x86_64 --cc=clang vs2022
    premake --os=linux --arch=x86_64 --cc=clang gmake2
```



<!-- ROADMAP -->
## Roadmap
This will be probably archived.

<!-- CONTRIBUTING -->
## Contributing
If you have a suggestion, please fork the repo and create a pull request. You can also simply open an issue with the tag "enhancement".  


<!-- LICENSE -->
## License
Distributed under the MIT License. See `LICENSE` file for more information.


<!-- ACKNOWLEDGEMENTS -->
## Acknowledgements
* [Best-README](https://github.com/othneildrew/Best-README-Template)
* [Raytracing in a weekend](https://raytracing.github.io/books/RayTracingInOneWeekend.html)


<!-- MARKDOWN LINKS & IMAGES -->
<!-- https://www.markdownguide.org/basic-syntax/#reference-style-links -->
[contributors-shield]: https://img.shields.io/github/contributors/inonitz/glsl-compute-raytracer?style=for-the-badge&color=blue
[contributors-url]: https://github.com/inonitz/glsl-compute-raytracer/graphs/contributors
[forks-shield]: https://img.shields.io/github/forks/inonitz/glsl-compute-raytracer?style=for-the-badge&color=blue
[forks-url]: https://github.com/inonitz/glsl-compute-raytracer/network/members
[stars-shield]: https://img.shields.io/github/stars/inonitz/glsl-compute-raytracer?style=for-the-badge&color=blue
[stars-url]: https://github.com/inonitz/glsl-compute-raytracer/stargazers
[issues-shield]: https://img.shields.io/github/issues/inonitz/glsl-compute-raytracer.svg?style=for-the-badge
[issues-url]: https://github.com/inonitz/glsl-compute-raytracer/issues
[license-shield]: https://img.shields.io/github/license/inonitz/glsl-compute-raytracer?style=for-the-badge
[license-url]: https://github.com/inonitz/glsl-compute-raytracer/blob/master/LICENSE
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=for-the-badge&logo=linkedin&colorB=555
[linkedin-url]: https://linkedin.com/in/linkedin_username
[product-screenshot]: images/screenshot.png
[Next.js]: https://img.shields.io/badge/next.js-000000?style=for-the-badge&logo=nextdotjs&logoColor=white

[ImGui-url]: https://github.com/ocornut/imgui
[ImGui.js]: https://avatars.githubusercontent.com/u/8225057?v=4&size=150
[glbinding-url]: https://github.com/cginternals/glbinding/releases/tag/v3.3.0
[glbinding.js]: https://raw.githubusercontent.com/cginternals/glbinding/master/glbinding-logo.svg?sanitize=true
[GLFW-url]: https://github.com/glfw/glfw/releases/tag/3.4
[GLFW.js]: https://avatars.githubusercontent.com/u/3905364?s=200&v=4&size=150
