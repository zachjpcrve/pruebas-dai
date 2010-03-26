##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=AgendaSQL
ConfigurationName      :=Debug
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
WorkspacePath          := "/home/hkr/Documentos/SVN/pruebas-dai"
ProjectPath            := "/home/hkr/Documentos/SVN/pruebas-dai/AgendaSQL"
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Alex
Date                   :=26/03/10
CodeLitePath           :="/home/hkr/.codelite"
LinkerName             :=g++
ArchiveTool            :=ar rcus
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=
DebugSwitch            :=-gstab
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
CompilerName           :=g++
C_CompilerName         :=gcc
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=
MakeDirCommand         :=mkdir -p
CmpOptions             := $(shell wx-config --cxxflags) $(Preprocessors)
LinkOptions            :=  $(shell wx-config --libs)
IncludePath            :=  "$(IncludeSwitch)." 
RcIncludePath          :=
Libs                   :=
LibPath                := "$(LibraryPathSwitch)." 


##
## User defined environment variables
##
Objects=$(IntermediateDirectory)/gui$(ObjectSuffix) $(IntermediateDirectory)/main$(ObjectSuffix) $(IntermediateDirectory)/cassContacto$(ObjectSuffix) 

##
## Main Build Targets 
##
all: $(OutputFile)

$(OutputFile): makeDirStep $(Objects)
	@$(MakeDirCommand) $(@D)
	$(LinkerName) $(OutputSwitch)$(OutputFile) $(Objects) $(LibPath) $(Libs) $(LinkOptions)

makeDirStep:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/gui$(ObjectSuffix): gui.cpp $(IntermediateDirectory)/gui$(DependSuffix)
	@test -d ./Debug || $(MakeDirCommand) ./Debug
	$(CompilerName) $(SourceSwitch) "/home/hkr/Documentos/SVN/pruebas-dai/AgendaSQL/gui.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/gui$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/gui$(DependSuffix): gui.cpp
	@test -d ./Debug || $(MakeDirCommand) ./Debug
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/gui$(ObjectSuffix) -MF$(IntermediateDirectory)/gui$(DependSuffix) -MM "/home/hkr/Documentos/SVN/pruebas-dai/AgendaSQL/gui.cpp"

$(IntermediateDirectory)/main$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main$(DependSuffix)
	@test -d ./Debug || $(MakeDirCommand) ./Debug
	$(CompilerName) $(SourceSwitch) "/home/hkr/Documentos/SVN/pruebas-dai/AgendaSQL/main.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/main$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main$(DependSuffix): main.cpp
	@test -d ./Debug || $(MakeDirCommand) ./Debug
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/main$(ObjectSuffix) -MF$(IntermediateDirectory)/main$(DependSuffix) -MM "/home/hkr/Documentos/SVN/pruebas-dai/AgendaSQL/main.cpp"

$(IntermediateDirectory)/cassContacto$(ObjectSuffix): cassContacto.cpp $(IntermediateDirectory)/cassContacto$(DependSuffix)
	@test -d ./Debug || $(MakeDirCommand) ./Debug
	$(CompilerName) $(SourceSwitch) "/home/hkr/Documentos/SVN/pruebas-dai/AgendaSQL/cassContacto.cpp" $(CmpOptions) $(ObjectSwitch)$(IntermediateDirectory)/cassContacto$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/cassContacto$(DependSuffix): cassContacto.cpp
	@test -d ./Debug || $(MakeDirCommand) ./Debug
	@$(CompilerName) $(CmpOptions) $(IncludePath) -MT$(IntermediateDirectory)/cassContacto$(ObjectSuffix) -MF$(IntermediateDirectory)/cassContacto$(DependSuffix) -MM "/home/hkr/Documentos/SVN/pruebas-dai/AgendaSQL/cassContacto.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/gui$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/gui$(DependSuffix)
	$(RM) $(IntermediateDirectory)/gui$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/main$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/main$(DependSuffix)
	$(RM) $(IntermediateDirectory)/main$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/cassContacto$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/cassContacto$(DependSuffix)
	$(RM) $(IntermediateDirectory)/cassContacto$(PreprocessSuffix)
	$(RM) $(OutputFile)


