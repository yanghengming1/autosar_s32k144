###############################################################################
# File Name  : Os_rules.mak                                                   #
# Description: Autosar makefile Template                                      #
#              This makefile is a template to implement the common            #
#              features of each project.                                      #
#              It is included by the Global.Makefile.target.make.$(Version)   #
#              and is supported from version 3.24 .                           #
#                                                                             #
# This Template is based on AUTOSAR_BSW_MakefileInterface.doc version 0.4     #
#                                                                             #
#-----------------------------------------------------------------------------#
#               C O P Y R I G H T                                             #
#-----------------------------------------------------------------------------#
# Copyright (c) 2017 by Vector Informatik GmbH.  All rights reserved.         #
#                                                                             #
#-----------------------------------------------------------------------------#
#               A U T H O R   I D E N T I T Y                                 #
#-----------------------------------------------------------------------------#
# Initials     Name                      Company                              #
# --------     ---------------------     -------------------------------------#
# Bse          Benjamin Seifert          Vector Informatik GmbH               #
# Biv          Ivan Begert               Vector Informatik GmbH               #
# Sso          Stefano Simoncelli        Vector Informatik GmbH               #
#-----------------------------------------------------------------------------#
#               R E V I S I O N   H I S T O R Y                               #
#-----------------------------------------------------------------------------#
# Date         Version     Sign Description                                   #
# ----------   -------     ---- ----------------------------------------------#
# 2017-04-06   2.00.00     Bse  Initial Version                               #
# 2017-08-29   2.01.00     Biv  TI Compiler specific file added               #
# 2017-09-08   2.02.00     Sso  Arm Compiler specific file added              #
#-----------------------------------------------------------------------------#
# TemplateVersion = 1.0                                                       #
# MAKEFILE        = 0.1                                                       #
###############################################################################

###############################################################
# REGISTRY
#

include $(ROOT)\BSW\Os\mak\Os_Core.mak

LIBRARIES_TO_BUILD      +=

CC_FILES_TO_BUILD       +=  Os\Os_Hal_Core.c              \
                            Os\Os_Hal_Context_v7m.c       \
                            Os\Os_Hal_Entry.c             \
                            Os\Os_Hal_Compiler_Arm.c      \
                            Os\Os_Hal_Compiler_Iar.c

CPP_FILES_TO_BUILD      +=
ASM_FILES_TO_BUILD      +=  Os\Os_Hal_ContextAsm.asm      \
                            Os\Os_Hal_Compiler_TiInt.asm

#LIBRARIES_LINK_ONLY     += (not yet supported)
#OBJECTS_LINK_ONLY       += (not yet supported)

#-------------------------------------------------------------------------------------------------
#only define new dirs, OBJ, LIB, LOG were created automaticly 
#-------------------------------------------------------------------------------------------------
DIRECTORIES_TO_CREATE   +=

#DEPEND_GCC_OPTS         += (not yet supported)

# e.g.:  GENERATED_SOURCE_FILES += $(GENDATA_DIR)\drv_par.c
GENERATED_SOURCE_FILES  +=  $(GENDATA_DIR)\Os_Hal_Context_Lcfg.c          \
                            $(GENDATA_DIR)\Os_Hal_Core_Lcfg.c             \
                            $(GENDATA_DIR)\Os_Hal_Entry_Lcfg.c            \
                            $(GENDATA_DIR)\Os_Hal_Interrupt_Lcfg.c        \
                            $(GENDATA_DIR)\Os_Hal_Kernel_Lcfg.c           \
                            $(GENDATA_DIR)\Os_Hal_MemoryProtection_Lcfg.c \
                            $(GENDATA_DIR)\Os_Hal_Timer_Lcfg.c 
                            
ASM_GENERATED_SOURCE_FILES += $(GENDATA_DIR)\Os_Hal_EntryAsm_Lcfg.asm 

#e.g.: COMMON_SOURCE_FILES     += $(GENDATA_DIR)\v_par.c
COMMON_SOURCE_FILES     += 

#-------------------------------------------------------------------------------------------------
# <project>.dep & <projekt>.lnk & <project>.bin and.....
# all in err\ & obj\ & lst\ & lib\ & log\ will be deleted by clean-rule automaticly
# so in this clean-rule it is only necessary to define additional files which
# were not delete automaticly.
# e.g.: $(<PATH>)\can_test.c
#-------------------------------------------------------------------------------------------------
MAKE_CLEAN_RULES        +=
#MAKE_GENERATE_RULES     +=
#MAKE_COMPILER_RULES     +=
#MAKE_DEBUG_RULES        +=
#MAKE_CONFIG_RULES       +=
#MAKE_ADD_RULES          +=


###############################################################
# REQUIRED   (defined in BaseMake (global.Makefile.target.make...))
#
# SSC_ROOT		(required)
# PROJECT_ROOT	(required)
#
# LIB_OUTPUT_PATH	(optional)
# OBJ_OUTPUT_PATH	(optional)
#
# OBJ_FILE_SUFFIX	
# LIB_FILE_SUFFIX
#
###############################################################


###############################################################
# PROVIDE   this Section can be used to define own additional rules
#
# In vendorx_can_cfg.mak:
# Please configure the project file:
#CAN_CONFIG_FILE = $(PROJECT_ROOT)\source\network\can\my_can_config.cfg

#In vendorx_can_config :
#generate_can_config:
	#$(SSC_ROOT)\core\com\can\tools\canconfiggen.exe -o $(CAN_CONFIG_FILE)


###############################################################
# SPECIFIC
#
# There are no rules defined for the Specific part of the 
# Rules-Makefile. Each author is free to create temporary 
# variables or to use other resources of GNU-MAKE
#
###############################################################


