# BmpEditor Program 
Made by : ***[Gad Amr](https://github.com/DBGad) - [Bavly Safwat](https://github.com/bavlysafwatt) - [Osama Mohamed](https://github.com/Osamamoo)***

Requested by: *[Dr. Mohammed El-Ramly](https://scholar.cu.edu.eg/?q=mramly/) in OOP course (Assignment 1)*

## The Idea of the BmpEditor Program 

* This is a simple Image processing console project.

* BmpEditor is an image processing tool that can apply different filters to a bit map image of size 256 x 256.

* BmpEditor has 2 versions:
  1. version that works with Grey Scale images
  2. version that works with Colored images 

* BmpEditor uses **bmplib.cpp** Library to load and save the images 
  * **bmplib** is a small library with four functions for loading the pixels of the image into a 2D or 3D array.
The library consists of two files bmplib.cpp and bmplib.h.


## Program Overview

***The menu that selects the image type :***
<div>
<img src="https://github.com/DBGad/Expidea.com/assets/122947749/fdde4051-9767-460d-a0b6-d28837114e6b">
</div>




***The list of filters that can be applied to an image before saving it:***

![Filters](https://github.com/DBGad/Expidea.com/assets/122947749/85552551-a944-4626-840e-07af22737947)

***Examples of the filters effects on Grey Scale Image:***


| Original Image |
| ----------- | 
|![photographer](https://github.com/DBGad/My-GitHub/assets/122947749/07921c0d-7b0c-45b5-b4db-5e731f150a90)| 

  
|  Black and White | Invert | Merge 2 Images | 
| ----------- |------- |------------- | 
 |![g1](https://github.com/DBGad/My-GitHub/assets/122947749/26fc3215-f001-4b32-b8ab-cb9e78644b86)|![g2](https://github.com/DBGad/My-GitHub/assets/122947749/58547988-ed69-4b71-aaaf-5fc24227fd2f)|![g3](https://github.com/DBGad/My-GitHub/assets/122947749/d08ba1ce-1ad0-447a-b71f-d6d8a25d4d84) |

 
| Flip | Rotate | Darken or Lighten |
| ----------- |------- |------------- | 
 |![g4](https://github.com/DBGad/My-GitHub/assets/122947749/59eb27f8-8e3c-457c-93b6-6f0a6bd11b97)|![g5](https://github.com/DBGad/My-GitHub/assets/122947749/4dd3f88b-d3bf-48c5-9a29-aa923c9f449d)|![g6](https://github.com/DBGad/My-GitHub/assets/122947749/d806c294-5e01-4ae6-ae6f-2c69f1d94ea0)|


| Detect Edges | Enlarge |  Shrink |
| ----------- |------- |------------- |
|![g7](https://github.com/DBGad/My-GitHub/assets/122947749/1b8430aa-cace-4a00-a3f3-ed456cb99746)|![g8](https://github.com/DBGad/My-GitHub/assets/122947749/c6295267-3ad9-4694-9404-c84990fb096f)|![g9](https://github.com/DBGad/My-GitHub/assets/122947749/59aae052-d603-4af5-a015-e0312bef2a12)|

 
| Mirror  | Shuffle  |  Blur |
| ----------- |------- |------------- |
| ![g10](https://github.com/DBGad/My-GitHub/assets/122947749/36fbf07e-658b-4a10-9a64-f6a2af83f1ec)| ![g11](https://github.com/DBGad/My-GitHub/assets/122947749/5876770d-3fce-4a95-b00d-176728723b42)| ![g12](https://github.com/DBGad/My-GitHub/assets/122947749/4b00e51d-f10c-40bc-a387-fa24f44df351)|


| Crop  | Skew Right  | Skew Up |
| ----------- |------- |------------- |
|![g13](https://github.com/DBGad/My-GitHub/assets/122947749/ec566f34-d52e-40ec-b6fd-b57cd91af8de)| ![g14](https://github.com/DBGad/My-GitHub/assets/122947749/7b9ea730-e7ac-4f38-a06c-81a29da30404)|![g15](https://github.com/DBGad/My-GitHub/assets/122947749/7cbe7247-fbc2-4398-b36c-2660ea852a1d)|





***Examples of the filters effects on Colored Image:***


| Original Image |
| ----------- | 
|![mario](https://github.com/DBGad/Bank-System/assets/122947749/3c03fda7-9cba-46f4-a50e-37d1fe3688af)| 

  
|  Black and White | Invert | Merge 2 Images | 
| ----------- |------- |------------- | 
|![c1](https://github.com/DBGad/My-GitHub/assets/122947749/613074a1-d1c1-4e07-a8e1-9dd5525a97b0)|![c2](https://github.com/DBGad/My-GitHub/assets/122947749/a1e23870-49dd-49b2-bf24-6210c36fa524)|![c3](https://github.com/DBGad/My-GitHub/assets/122947749/ff02f46d-457d-4f67-8df4-566c793537ec)|
 
| Flip | Rotate | Darken or Lighten |
| ----------- |------- |------------- | 
 |![c4](https://github.com/DBGad/My-GitHub/assets/122947749/81590dcf-bf50-4df2-acb2-4343514a9808)|![c5](https://github.com/DBGad/My-GitHub/assets/122947749/5c7bc520-5c55-4253-9250-3fc27b461ac0)|![c6](https://github.com/DBGad/My-GitHub/assets/122947749/4e1bd034-bdd7-4841-8d0f-e8f814361d93)|

| Detect Edges | Enlarge |  Shrink |
| ----------- |------- |------------- |
|![c7](https://github.com/DBGad/My-GitHub/assets/122947749/96bb2571-deec-44ff-aca6-83476ad13e55)|![c8](https://github.com/DBGad/My-GitHub/assets/122947749/649e5a28-1095-4fa6-a2a8-34c6657be43b)|![c9](https://github.com/DBGad/My-GitHub/assets/122947749/69e055c9-6002-4c4f-ad50-112cd3f1df49)|
 
| Mirror  | Shuffle  |  Blur |
| ----------- |------- |------------- |
|![c10](https://github.com/DBGad/My-GitHub/assets/122947749/5f5447f4-e04f-4b21-a838-01efa913b07b)|![c11](https://github.com/DBGad/My-GitHub/assets/122947749/b4e7ebdd-ae75-41ef-97d8-34932ea70e04)|![c12](https://github.com/DBGad/My-GitHub/assets/122947749/d3711901-d0eb-4037-a3aa-ca31e99fb2dd)|


| Crop  | Skew Right  | Skew Up |
| ----------- |------- |------------- |
|![c13](https://github.com/DBGad/My-GitHub/assets/122947749/3dfa5faa-3932-4729-bb07-12ddffc375ea)|![c14](https://github.com/DBGad/My-GitHub/assets/122947749/289a80cf-8664-473f-95c1-136c75f5fe32)|![c15](https://github.com/DBGad/My-GitHub/assets/122947749/e6e57199-c79c-48b5-a54a-7ff85a971cce)|



### **Important Note**
1. add two folders thier names is "tmp" and "imgs" without "" 
	. put Your Images in "imgs" Folder
	. Make Folder "tmp" empty

2. check your cwd (current Working directory) 

 if Your cwd in "cmake-build-debug"  

    - put the folders in "cmake-build-debug" file


 if  Your cwd is not in "cmake-build-debug"

    - put the folders next to "main.cpp" file

 
