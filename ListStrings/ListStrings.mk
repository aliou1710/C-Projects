##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=ListStrings
ConfigurationName      :=Debug
WorkspaceConfiguration :=Debug
WorkspacePath          :=D:/Cours_bloc_MA2/C++/cours/aliWorkspace
ProjectPath            :=D:/Cours_bloc_MA2/C++/cours/cours/5IN0301/exercices/ListStrings
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=aliou
Date                   :=07/12/2022
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
ObjectsFileList        :="ListStrings.txt"
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
Objects0=$(IntermediateDirectory)/algo.cpp$(ObjectSuffix) $(IntermediateDirectory)/list.cpp$(ObjectSuffix) $(IntermediateDirectory)/ListStringsTest.cpp$(ObjectSuffix) 



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
$(IntermediateDirectory)/algo.cpp$(ObjectSuffix): algo.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/algo.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/algo.cpp$(DependSuffix) -MM algo.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/Cours_bloc_MA2/C++/cours/cours/5IN0301/exercices/ListStrings/algo.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/algo.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/algo.cpp$(PreprocessSuffix): algo.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/algo.cpp$(PreprocessSuffix) algo.cpp

$(IntermediateDirectory)/list.cpp$(ObjectSuffix): list.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/list.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/list.cpp$(DependSuffix) -MM list.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/Cours_bloc_MA2/C++/cours/cours/5IN0301/exercices/ListStrings/list.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/list.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/list.cpp$(PreprocessSuffix): list.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/list.cpp$(PreprocessSuffix) list.cpp

$(IntermediateDirectory)/ListStringsTest.cpp$(ObjectSuffix): ListStringsTest.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/ListStringsTest.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/ListStringsTest.cpp$(DependSuffix) -MM ListStringsTest.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "D:/Cours_bloc_MA2/C++/cours/cours/5IN0301/exercices/ListStrings/ListStringsTest.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/ListStringsTest.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/ListStringsTest.cpp$(PreprocessSuffix): ListStringsTest.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/ListStringsTest.cpp$(PreprocessSuffix) ListStringsTest.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/


