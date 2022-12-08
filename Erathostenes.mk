##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Erathostenes
ConfigurationName      :=Debug
WorkspaceConfiguration :=Debug
WorkspacePath          :=D:/Cours_bloc_MA2/C++/cours/aliWorkspace
ProjectPath            :=D:/Cours_bloc_MA2/C++/cours/cours/5IN0301/exercices/Erathostenes
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=aliou
Date                   :=02/12/2022
CodeLitePath           :="C:/Program Files/CodeLite"
LinkerName             :="D:/ALL APPLICATION INSTALLED FILES/Codelite/C++/SOFTWARE/mingw32/bin/g++.exe"
SharedObjectLinkerName :="D:/ALL APPLICATION INSTALLED FILES/Codelite/C++/SOFTWARE/mingw32/bin/g++.exe" -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputDirectory        :=$(IntermediateDirectory)
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="Erathostenes.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :="D:/ALL APPLICATION INSTALLED FILES/Codelite/C++/SOFTWARE/mingw32/bin/windres.exe"
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch)./../../syllabus/InOut/src $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := $(LibrarySwitch)InOut 
ArLibs                 :=  "InOut" 
LibPath                := $(LibraryPathSwitch). $(LibraryPathSwitch)./../../syllabus/InOut/Debug 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overridden using an environment variable
##
AR       := "D:/ALL APPLICATION INSTALLED FILES/Codelite/C++/SOFTWARE/mingw32/bin/ar.exe" rcu
CXX      := "D:/ALL APPLICATION INSTALLED FILES/Codelite/C++/SOFTWARE/mingw32/bin/g++.exe"
CC       := "D:/ALL APPLICATION INSTALLED FILES/Codelite/C++/SOFTWARE/mingw32/bin/gcc.exe"
CXXFLAGS := -std=c++17 -pedantic-errors -Wall -g -O0 $(Preprocessors)
CFLAGS   := -std=c90 -pedantic-errors -Wall -g -O0 $(Preprocessors)
ASFLAGS  := 
AS       := "D:/ALL APPLICATION INSTALLED FILES/Codelite/C++/SOFTWARE/mingw32/bin/as.exe"


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
Objects0=$(IntermediateDirectory)/src_Erathostenes.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@$(MakeDirCommand) "./Debug"


$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/src_Erathostenes.cpp$(ObjectSuffix): src/Erathostenes.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/src_Erathostenes.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/src_Erathostenes.cpp$(DependSuffix) -MM src/Erathostenes.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/Cours_bloc_MA2/C++/cours/cours/5IN0301/exercices/Erathostenes/src/Erathostenes.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/src_Erathostenes.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/src_Erathostenes.cpp$(PreprocessSuffix): src/Erathostenes.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/src_Erathostenes.cpp$(PreprocessSuffix) src/Erathostenes.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


