// Copyright 2018 yuzu emulator team
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#include "common/logging/log.h"
#include "core/file_sys/control_metadata.h"
#include "core/file_sys/patch_manager.h"
#include "core/hle/ipc_helpers.h"
#include "core/hle/kernel/hle_ipc.h"
#include "core/hle/service/ns/ns.h"
#include "core/hle/service/ns/pl_u.h"

namespace Service::NS {

class IAccountProxyInterface final : public ServiceFramework<IAccountProxyInterface> {
public:
    explicit IAccountProxyInterface() : ServiceFramework{"IAccountProxyInterface"} {
        // clang-format off
        static const FunctionInfo functions[] = {
            {0, nullptr, "CreateUserAccount"},
        };
        // clang-format on

        RegisterHandlers(functions);
    }
};

class IApplicationManagerInterface final : public ServiceFramework<IApplicationManagerInterface> {
public:
    explicit IApplicationManagerInterface() : ServiceFramework{"IApplicationManagerInterface"} {
        // clang-format off
        static const FunctionInfo functions[] = {
            {0, nullptr, "ListApplicationRecord"},
            {1, nullptr, "GenerateApplicationRecordCount"},
            {2, nullptr, "GetApplicationRecordUpdateSystemEvent"},
            {3, nullptr, "GetApplicationViewDeprecated"},
            {4, nullptr, "DeleteApplicationEntity"},
            {5, nullptr, "DeleteApplicationCompletely"},
            {6, nullptr, "IsAnyApplicationEntityRedundant"},
            {7, nullptr, "DeleteRedundantApplicationEntity"},
            {8, nullptr, "IsApplicationEntityMovable"},
            {9, nullptr, "MoveApplicationEntity"},
            {11, nullptr, "CalculateApplicationOccupiedSize"},
            {16, nullptr, "PushApplicationRecord"},
            {17, nullptr, "ListApplicationRecordContentMeta"},
            {19, nullptr, "LaunchApplication"},
            {21, nullptr, "GetApplicationContentPath"},
            {22, nullptr, "TerminateApplication"},
            {23, nullptr, "ResolveApplicationContentPath"},
            {26, nullptr, "BeginInstallApplication"},
            {27, nullptr, "DeleteApplicationRecord"},
            {30, nullptr, "RequestApplicationUpdateInfo"},
            {32, nullptr, "CancelApplicationDownload"},
            {33, nullptr, "ResumeApplicationDownload"},
            {35, nullptr, "UpdateVersionList"},
            {36, nullptr, "PushLaunchVersion"},
            {37, nullptr, "ListRequiredVersion"},
            {38, nullptr, "CheckApplicationLaunchVersion"},
            {39, nullptr, "CheckApplicationLaunchRights"},
            {40, nullptr, "GetApplicationLogoData"},
            {41, nullptr, "CalculateApplicationDownloadRequiredSize"},
            {42, nullptr, "CleanupSdCard"},
            {43, nullptr, "CheckSdCardMountStatus"},
            {44, nullptr, "GetSdCardMountStatusChangedEvent"},
            {45, nullptr, "GetGameCardAttachmentEvent"},
            {46, nullptr, "GetGameCardAttachmentInfo"},
            {47, nullptr, "GetTotalSpaceSize"},
            {48, nullptr, "GetFreeSpaceSize"},
            {49, nullptr, "GetSdCardRemovedEvent"},
            {52, nullptr, "GetGameCardUpdateDetectionEvent"},
            {53, nullptr, "DisableApplicationAutoDelete"},
            {54, nullptr, "EnableApplicationAutoDelete"},
            {55, nullptr, "GetApplicationDesiredLanguage"},
            {56, nullptr, "SetApplicationTerminateResult"},
            {57, nullptr, "ClearApplicationTerminateResult"},
            {58, nullptr, "GetLastSdCardMountUnexpectedResult"},
            {59, nullptr, "ConvertApplicationLanguageToLanguageCode"},
            {60, nullptr, "ConvertLanguageCodeToApplicationLanguage"},
            {61, nullptr, "GetBackgroundDownloadStressTaskInfo"},
            {62, nullptr, "GetGameCardStopper"},
            {63, nullptr, "IsSystemProgramInstalled"},
            {64, nullptr, "StartApplyDeltaTask"},
            {65, nullptr, "GetRequestServerStopper"},
            {66, nullptr, "GetBackgroundApplyDeltaStressTaskInfo"},
            {67, nullptr, "CancelApplicationApplyDelta"},
            {68, nullptr, "ResumeApplicationApplyDelta"},
            {69, nullptr, "CalculateApplicationApplyDeltaRequiredSize"},
            {70, nullptr, "ResumeAll"},
            {71, nullptr, "GetStorageSize"},
            {80, nullptr, "RequestDownloadApplication"},
            {81, nullptr, "RequestDownloadAddOnContent"},
            {82, nullptr, "DownloadApplication"},
            {83, nullptr, "CheckApplicationResumeRights"},
            {84, nullptr, "GetDynamicCommitEvent"},
            {85, nullptr, "RequestUpdateApplication2"},
            {86, nullptr, "EnableApplicationCrashReport"},
            {87, nullptr, "IsApplicationCrashReportEnabled"},
            {90, nullptr, "BoostSystemMemoryResourceLimit"},
            {91, nullptr, "Unknown1"},
            {92, nullptr, "Unknown2"},
            {93, nullptr, "GetMainApplicationProgramIndex"},
            {94, nullptr, "LaunchApplication2"},
            {95, nullptr, "GetApplicationLaunchInfo"},
            {96, nullptr, "AcquireApplicationLaunchInfo"},
            {97, nullptr, "GetMainApplicationProgramIndex2"},
            {98, nullptr, "EnableApplicationAllThreadDumpOnCrash"},
            {100, nullptr, "ResetToFactorySettings"},
            {101, nullptr, "ResetToFactorySettingsWithoutUserSaveData"},
            {102, nullptr, "ResetToFactorySettingsForRefurbishment"},
            {200, nullptr, "CalculateUserSaveDataStatistics"},
            {201, nullptr, "DeleteUserSaveDataAll"},
            {210, nullptr, "DeleteUserSystemSaveData"},
            {211, nullptr, "DeleteSaveData"},
            {220, nullptr, "UnregisterNetworkServiceAccount"},
            {221, nullptr, "UnregisterNetworkServiceAccountWithUserSaveDataDeletion"},
            {300, nullptr, "GetApplicationShellEvent"},
            {301, nullptr, "PopApplicationShellEventInfo"},
            {302, nullptr, "LaunchLibraryApplet"},
            {303, nullptr, "TerminateLibraryApplet"},
            {304, nullptr, "LaunchSystemApplet"},
            {305, nullptr, "TerminateSystemApplet"},
            {306, nullptr, "LaunchOverlayApplet"},
            {307, nullptr, "TerminateOverlayApplet"},
            {400, &IApplicationManagerInterface::GetApplicationControlData, "GetApplicationControlData"},
            {401, nullptr, "InvalidateAllApplicationControlCache"},
            {402, nullptr, "RequestDownloadApplicationControlData"},
            {403, nullptr, "GetMaxApplicationControlCacheCount"},
            {404, nullptr, "InvalidateApplicationControlCache"},
            {405, nullptr, "ListApplicationControlCacheEntryInfo"},
            {406, nullptr, "GetApplicationControlProperty"},
            {502, nullptr, "RequestCheckGameCardRegistration"},
            {503, nullptr, "RequestGameCardRegistrationGoldPoint"},
            {504, nullptr, "RequestRegisterGameCard"},
            {505, nullptr, "GetGameCardMountFailureEvent"},
            {506, nullptr, "IsGameCardInserted"},
            {507, nullptr, "EnsureGameCardAccess"},
            {508, nullptr, "GetLastGameCardMountFailureResult"},
            {509, nullptr, "ListApplicationIdOnGameCard"},
            {600, nullptr, "CountApplicationContentMeta"},
            {601, nullptr, "ListApplicationContentMetaStatus"},
            {602, nullptr, "ListAvailableAddOnContent"},
            {603, nullptr, "GetOwnedApplicationContentMetaStatus"},
            {604, nullptr, "RegisterContentsExternalKey"},
            {605, nullptr, "ListApplicationContentMetaStatusWithRightsCheck"},
            {606, nullptr, "GetContentMetaStorage"},
            {607, nullptr, "ListAvailableAddOnContent"},
            {700, nullptr, "PushDownloadTaskList"},
            {701, nullptr, "ClearTaskStatusList"},
            {702, nullptr, "RequestDownloadTaskList"},
            {703, nullptr, "RequestEnsureDownloadTask"},
            {704, nullptr, "ListDownloadTaskStatus"},
            {705, nullptr, "RequestDownloadTaskListData"},
            {800, nullptr, "RequestVersionList"},
            {801, nullptr, "ListVersionList"},
            {802, nullptr, "RequestVersionListData"},
            {900, nullptr, "GetApplicationRecord"},
            {901, nullptr, "GetApplicationRecordProperty"},
            {902, nullptr, "EnableApplicationAutoUpdate"},
            {903, nullptr, "DisableApplicationAutoUpdate"},
            {904, nullptr, "TouchApplication"},
            {905, nullptr, "RequestApplicationUpdate"},
            {906, nullptr, "IsApplicationUpdateRequested"},
            {907, nullptr, "WithdrawApplicationUpdateRequest"},
            {908, nullptr, "ListApplicationRecordInstalledContentMeta"},
            {909, nullptr, "WithdrawCleanupAddOnContentsWithNoRightsRecommendation"},
            {910, nullptr, "Unknown3"},
            {911, nullptr, "SetPreInstalledApplication"},
            {912, nullptr, "ClearPreInstalledApplicationFlag"},
            {1000, nullptr, "RequestVerifyApplicationDeprecated"},
            {1001, nullptr, "CorruptApplicationForDebug"},
            {1002, nullptr, "RequestVerifyAddOnContentsRights"},
            {1003, nullptr, "RequestVerifyApplication"},
            {1004, nullptr, "CorruptContentForDebug"},
            {1200, nullptr, "NeedsUpdateVulnerability"},
            {1300, nullptr, "IsAnyApplicationEntityInstalled"},
            {1301, nullptr, "DeleteApplicationContentEntities"},
            {1302, nullptr, "CleanupUnrecordedApplicationEntity"},
            {1303, nullptr, "CleanupAddOnContentsWithNoRights"},
            {1304, nullptr, "DeleteApplicationContentEntity"},
            {1305, nullptr, "TryDeleteRunningApplicationEntity"},
            {1306, nullptr, "TryDeleteRunningApplicationCompletely"},
            {1307, nullptr, "TryDeleteRunningApplicationContentEntities"},
            {1308, nullptr, "DeleteApplicationCompletelyForDebug"},
            {1309, nullptr, "CleanupUnavailableAddOnContents"},
            {1400, nullptr, "PrepareShutdown"},
            {1500, nullptr, "FormatSdCard"},
            {1501, nullptr, "NeedsSystemUpdateToFormatSdCard"},
            {1502, nullptr, "GetLastSdCardFormatUnexpectedResult"},
            {1504, nullptr, "InsertSdCard"},
            {1505, nullptr, "RemoveSdCard"},
            {1600, nullptr, "GetSystemSeedForPseudoDeviceId"},
            {1601, nullptr, "ResetSystemSeedForPseudoDeviceId"},
            {1700, nullptr, "ListApplicationDownloadingContentMeta"},
            {1701, nullptr, "GetApplicationView"},
            {1702, nullptr, "GetApplicationDownloadTaskStatus"},
            {1703, nullptr, "GetApplicationViewDownloadErrorContext"},
            {1800, nullptr, "IsNotificationSetupCompleted"},
            {1801, nullptr, "GetLastNotificationInfoCount"},
            {1802, nullptr, "ListLastNotificationInfo"},
            {1803, nullptr, "ListNotificationTask"},
            {1900, nullptr, "IsActiveAccount"},
            {1901, nullptr, "RequestDownloadApplicationPrepurchasedRights"},
            {1902, nullptr, "GetApplicationTicketInfo"},
            {2000, nullptr, "GetSystemDeliveryInfo"},
            {2001, nullptr, "SelectLatestSystemDeliveryInfo"},
            {2002, nullptr, "VerifyDeliveryProtocolVersion"},
            {2003, nullptr, "GetApplicationDeliveryInfo"},
            {2004, nullptr, "HasAllContentsToDeliver"},
            {2005, nullptr, "CompareApplicationDeliveryInfo"},
            {2006, nullptr, "CanDeliverApplication"},
            {2007, nullptr, "ListContentMetaKeyToDeliverApplication"},
            {2008, nullptr, "NeedsSystemUpdateToDeliverApplication"},
            {2009, nullptr, "EstimateRequiredSize"},
            {2010, nullptr, "RequestReceiveApplication"},
            {2011, nullptr, "CommitReceiveApplication"},
            {2012, nullptr, "GetReceiveApplicationProgress"},
            {2013, nullptr, "RequestSendApplication"},
            {2014, nullptr, "GetSendApplicationProgress"},
            {2015, nullptr, "CompareSystemDeliveryInfo"},
            {2016, nullptr, "ListNotCommittedContentMeta"},
            {2017, nullptr, "CreateDownloadTask"},
            {2018, nullptr, "Unknown4"},
            {2050, nullptr, "Unknown5"},
            {2100, nullptr, "Unknown6"},
            {2101, nullptr, "Unknown7"},
            {2150, nullptr, "CreateRightsEnvironment"},
            {2151, nullptr, "DestroyRightsEnvironment"},
            {2152, nullptr, "ActivateRightsEnvironment"},
            {2153, nullptr, "DeactivateRightsEnvironment"},
            {2154, nullptr, "ForceActivateRightsContextForExit"},
            {2160, nullptr, "AddTargetApplicationToRightsEnvironment"},
            {2161, nullptr, "SetUsersToRightsEnvironment"},
            {2170, nullptr, "GetRightsEnvironmentStatus"},
            {2171, nullptr, "GetRightsEnvironmentStatusChangedEvent"},
            {2180, nullptr, "RequestExtendRightsInRightsEnvironment"},
            {2181, nullptr, "GetLastResultOfExtendRightsInRightsEnvironment"},
            {2182, nullptr, "SetActiveRightsContextUsingStateToRightsEnvironment"},
            {2190, nullptr, "GetRightsEnvironmentHandleForApplication"},
            {2199, nullptr, "GetRightsEnvironmentCountForDebug"},
            {2200, nullptr, "Unknown8"},
            {2201, nullptr, "Unknown9"},
            {2250, nullptr, "Unknown10"},
            {2300, nullptr, "Unknown11"},
        };
        // clang-format on

        RegisterHandlers(functions);
    }

    void GetApplicationControlData(Kernel::HLERequestContext& ctx) {
        IPC::RequestParser rp{ctx};
        const auto flag = rp.PopRaw<u64>();
        LOG_DEBUG(Service_NS, "called with flag={:016X}", flag);

        const auto title_id = rp.PopRaw<u64>();

        const auto size = ctx.GetWriteBufferSize();

        const FileSys::PatchManager pm{title_id};
        const auto control = pm.GetControlMetadata();

        std::vector<u8> out;

        if (control.first != nullptr) {
            if (size < 0x4000) {
                LOG_ERROR(Service_NS,
                          "output buffer is too small! (actual={:016X}, expected_min=0x4000)",
                          size);
                IPC::ResponseBuilder rb{ctx, 2};
                // TODO(DarkLordZach): Find a better error code for this.
                rb.Push(ResultCode(-1));
                return;
            }

            out.resize(0x4000);
            const auto bytes = control.first->GetRawBytes();
            std::memcpy(out.data(), bytes.data(), bytes.size());
        } else {
            LOG_WARNING(Service_NS, "missing NACP data for title_id={:016X}, defaulting to zeros.",
                        title_id);
            out.resize(std::min<u64>(0x4000, size));
        }

        if (control.second != nullptr) {
            if (size < 0x4000 + control.second->GetSize()) {
                LOG_ERROR(Service_NS,
                          "output buffer is too small! (actual={:016X}, expected_min={:016X})",
                          size, 0x4000 + control.second->GetSize());
                IPC::ResponseBuilder rb{ctx, 2};
                // TODO(DarkLordZach): Find a better error code for this.
                rb.Push(ResultCode(-1));
                return;
            }

            out.resize(0x4000 + control.second->GetSize());
            control.second->Read(out.data() + 0x4000, control.second->GetSize());
        } else {
            LOG_WARNING(Service_NS, "missing icon data for title_id={:016X}, defaulting to zeros.",
                        title_id);
        }

        ctx.WriteBuffer(out);

        IPC::ResponseBuilder rb{ctx, 3};
        rb.Push(RESULT_SUCCESS);
        rb.Push<u32>(static_cast<u32>(out.size()));
    }
};

class IApplicationVersionInterface final : public ServiceFramework<IApplicationVersionInterface> {
public:
    explicit IApplicationVersionInterface() : ServiceFramework{"IApplicationVersionInterface"} {
        // clang-format off
        static const FunctionInfo functions[] = {
            {0, nullptr, "GetLaunchRequiredVersion"},
            {1, nullptr, "UpgradeLaunchRequiredVersion"},
            {35, nullptr, "UpdateVersionList"},
            {36, nullptr, "PushLaunchVersion"},
            {37, nullptr, "ListRequiredVersion"},
            {800, nullptr, "RequestVersionList"},
            {801, nullptr, "ListVersionList"},
            {802, nullptr, "RequestVersionListData"},
            {1000, nullptr, "PerformAutoUpdate"},
        };
        // clang-format on

        RegisterHandlers(functions);
    }
};

class IContentManagerInterface final : public ServiceFramework<IContentManagerInterface> {
public:
    explicit IContentManagerInterface() : ServiceFramework{"IContentManagerInterface"} {
        // clang-format off
        static const FunctionInfo functions[] = {
            {11, nullptr, "CalculateApplicationOccupiedSize"},
            {43, nullptr, "CheckSdCardMountStatus"},
            {47, nullptr, "GetTotalSpaceSize"},
            {48, nullptr, "GetFreeSpaceSize"},
            {600, nullptr, "CountApplicationContentMeta"},
            {601, nullptr, "ListApplicationContentMetaStatus"},
            {605, nullptr, "ListApplicationContentMetaStatusWithRightsCheck"},
            {607, nullptr, "IsAnyApplicationRunning"},
        };
        // clang-format on

        RegisterHandlers(functions);
    }
};

class IDocumentInterface final : public ServiceFramework<IDocumentInterface> {
public:
    explicit IDocumentInterface() : ServiceFramework{"IDocumentInterface"} {
        // clang-format off
        static const FunctionInfo functions[] = {
            {21, nullptr, "GetApplicationContentPath"},
            {23, nullptr, "ResolveApplicationContentPath"},
        };
        // clang-format on

        RegisterHandlers(functions);
    }
};

class IDownloadTaskInterface final : public ServiceFramework<IDownloadTaskInterface> {
public:
    explicit IDownloadTaskInterface() : ServiceFramework{"IDownloadTaskInterface"} {
        // clang-format off
        static const FunctionInfo functions[] = {
            {701, nullptr, "ClearTaskStatusList"},
            {702, nullptr, "RequestDownloadTaskList"},
            {703, nullptr, "RequestEnsureDownloadTask"},
            {704, nullptr, "ListDownloadTaskStatus"},
            {705, nullptr, "RequestDownloadTaskListData"},
            {706, nullptr, "TryCommitCurrentApplicationDownloadTask"},
            {707, nullptr, "EnableAutoCommit"},
            {708, nullptr, "DisableAutoCommit"},
            {709, nullptr, "TriggerDynamicCommitEvent"},
        };
        // clang-format on

        RegisterHandlers(functions);
    }
};

class IECommerceInterface final : public ServiceFramework<IECommerceInterface> {
public:
    explicit IECommerceInterface() : ServiceFramework{"IECommerceInterface"} {
        // clang-format off
        static const FunctionInfo functions[] = {
            {0, nullptr, "RequestLinkDevice"},
        };
        // clang-format on

        RegisterHandlers(functions);
    }
};

class IFactoryResetInterface final : public ServiceFramework<IFactoryResetInterface> {
public:
    explicit IFactoryResetInterface() : ServiceFramework{"IFactoryResetInterface"} {
        // clang-format off
        static const FunctionInfo functions[] = {
            {100, nullptr, "ResetToFactorySettings"},
            {101, nullptr, "ResetToFactorySettingsWithoutUserSaveData"},
            {102, nullptr, "ResetToFactorySettingsForRefurbishment "},
        };
        // clang-format on

        RegisterHandlers(functions);
    }
};

class NS final : public ServiceFramework<NS> {
public:
    explicit NS(const char* name) : ServiceFramework{name} {
        // clang-format off
        static const FunctionInfo functions[] = {
            {7992, &NS::PushInterface<IECommerceInterface>, "GetECommerceInterface"},
            {7993, &NS::PushInterface<IApplicationVersionInterface>, "GetApplicationVersionInterface"},
            {7994, &NS::PushInterface<IFactoryResetInterface>, "GetFactoryResetInterface"},
            {7995, &NS::PushInterface<IAccountProxyInterface>, "GetAccountProxyInterface"},
            {7996, &NS::PushInterface<IApplicationManagerInterface>, "GetApplicationManagerInterface"},
            {7997, &NS::PushInterface<IDownloadTaskInterface>, "GetDownloadTaskInterface"},
            {7998, &NS::PushInterface<IContentManagerInterface>, "GetContentManagementInterface"},
            {7999, &NS::PushInterface<IDocumentInterface>, "GetDocumentInterface"},
        };
        // clang-format on

        RegisterHandlers(functions);
    }

private:
    template <typename T>
    void PushInterface(Kernel::HLERequestContext& ctx) {
        LOG_DEBUG(Service_NS, "called");

        IPC::ResponseBuilder rb{ctx, 2, 0, 1};
        rb.Push(RESULT_SUCCESS);
        rb.PushIpcInterface<T>();
    }
};

class NS_DEV final : public ServiceFramework<NS_DEV> {
public:
    explicit NS_DEV() : ServiceFramework{"ns:dev"} {
        // clang-format off
        static const FunctionInfo functions[] = {
            {0, nullptr, "LaunchProgram"},
            {1, nullptr, "TerminateProcess"},
            {2, nullptr, "TerminateProgram"},
            {4, nullptr, "GetShellEventHandle"},
            {5, nullptr, "GetShellEventInfo"},
            {6, nullptr, "TerminateApplication"},
            {7, nullptr, "PrepareLaunchProgramFromHost"},
            {8, nullptr, "LaunchApplication"},
            {9, nullptr, "LaunchApplicationWithStorageId"},
            {10, nullptr, "TerminateApplication2"},
            {11, nullptr, "GetRunningApplicationProcessId"},
            {12, nullptr, "SetCurrentApplicationRightsEnvironmentCanBeActive"},
        };
        // clang-format on

        RegisterHandlers(functions);
    }
};

class ISystemUpdateControl final : public ServiceFramework<ISystemUpdateControl> {
public:
    explicit ISystemUpdateControl() : ServiceFramework{"ISystemUpdateControl"} {
        // clang-format off
        static const FunctionInfo functions[] = {
            {0, nullptr, "HasDownloaded"},
            {1, nullptr, "RequestCheckLatestUpdate"},
            {2, nullptr, "RequestDownloadLatestUpdate"},
            {3, nullptr, "GetDownloadProgress"},
            {4, nullptr, "ApplyDownloadedUpdate"},
            {5, nullptr, "RequestPrepareCardUpdate"},
            {6, nullptr, "GetPrepareCardUpdateProgress"},
            {7, nullptr, "HasPreparedCardUpdate"},
            {8, nullptr, "ApplyCardUpdate"},
            {9, nullptr, "GetDownloadedEulaDataSize"},
            {10, nullptr, "GetDownloadedEulaData"},
            {11, nullptr, "SetupCardUpdate"},
            {12, nullptr, "GetPreparedCardUpdateEulaDataSize"},
            {13, nullptr, "GetPreparedCardUpdateEulaData"},
            {14, nullptr, "SetupCardUpdateViaSystemUpdater"},
            {15, nullptr, "HasReceived"},
            {16, nullptr, "RequestReceiveSystemUpdate"},
            {17, nullptr, "GetReceiveProgress"},
            {18, nullptr, "ApplyReceivedUpdate"},
            {19, nullptr, "GetReceivedEulaDataSize"},
            {20, nullptr, "GetReceivedEulaData"},
            {21, nullptr, "SetupToReceiveSystemUpdate"},
            {22, nullptr, "RequestCheckLatestUpdateIncludesRebootlessUpdate"},
        };
        // clang-format on

        RegisterHandlers(functions);
    }
};

class NS_SU final : public ServiceFramework<NS_SU> {
public:
    explicit NS_SU() : ServiceFramework{"ns:su"} {
        // clang-format off
        static const FunctionInfo functions[] = {
            {0, nullptr, "GetBackgroundNetworkUpdateState"},
            {1, &NS_SU::OpenSystemUpdateControl, "OpenSystemUpdateControl"},
            {2, nullptr, "NotifyExFatDriverRequired"},
            {3, nullptr, "ClearExFatDriverStatusForDebug"},
            {4, nullptr, "RequestBackgroundNetworkUpdate"},
            {5, nullptr, "NotifyBackgroundNetworkUpdate"},
            {6, nullptr, "NotifyExFatDriverDownloadedForDebug"},
            {9, nullptr, "GetSystemUpdateNotificationEventForContentDelivery"},
            {10, nullptr, "NotifySystemUpdateForContentDelivery"},
            {11, nullptr, "PrepareShutdown"},
            {16, nullptr, "DestroySystemUpdateTask"},
            {17, nullptr, "RequestSendSystemUpdate"},
            {18, nullptr, "GetSendSystemUpdateProgress"},
        };
        // clang-format on

        RegisterHandlers(functions);
    }

private:
    void OpenSystemUpdateControl(Kernel::HLERequestContext& ctx) {
        LOG_DEBUG(Service_NS, "called");

        IPC::ResponseBuilder rb{ctx, 2, 0, 1};
        rb.Push(RESULT_SUCCESS);
        rb.PushIpcInterface<ISystemUpdateControl>();
    }
};

class NS_VM final : public ServiceFramework<NS_VM> {
public:
    explicit NS_VM() : ServiceFramework{"ns:vm"} {
        // clang-format off
        static const FunctionInfo functions[] = {
            {1200, nullptr, "NeedsUpdateVulnerability"},
            {1201, nullptr, "UpdateSafeSystemVersionForDebug"},
            {1202, nullptr, "GetSafeSystemVersion"},
        };
        // clang-format on

        RegisterHandlers(functions);
    }
};

void InstallInterfaces(SM::ServiceManager& service_manager) {
    std::make_shared<NS>("ns:am2")->InstallAsService(service_manager);
    std::make_shared<NS>("ns:ec")->InstallAsService(service_manager);
    std::make_shared<NS>("ns:rid")->InstallAsService(service_manager);
    std::make_shared<NS>("ns:rt")->InstallAsService(service_manager);
    std::make_shared<NS>("ns:web")->InstallAsService(service_manager);

    std::make_shared<NS_DEV>()->InstallAsService(service_manager);
    std::make_shared<NS_SU>()->InstallAsService(service_manager);
    std::make_shared<NS_VM>()->InstallAsService(service_manager);

    std::make_shared<PL_U>()->InstallAsService(service_manager);
}

} // namespace Service::NS
