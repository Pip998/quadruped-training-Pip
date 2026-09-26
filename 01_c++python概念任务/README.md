一、文件夹说明：

1.源文件与导出文件：包含从nwwolf仓库中下载下来的urdf文件，以及从URDFstudio中导出的mjcf文件。其中，在导出mjcf时因需要勾选浮动基座选项，故在原urdf文件中赋予了base模块一微小质量以保证能顺利渲染。

2.build.cpp：即Cpp语言做法。其中包含Cmakelist.txt，meshes包，simulate_laying_dog.cpp，优化过的xml文件，和laying_dog的结果。

3.build.py：即python做法。包含meshes包，优化前后两版的xml与py文件。

4.结果视频：包含初步仿真视频以及优化线程后的仿真视频。



