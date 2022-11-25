//  OpenVPN 3 Linux client -- Next generation OpenVPN client
//
//  Copyright (C) 2022         OpenVPN, Inc. <sales@openvpn.net>
//  Copyright (C) 2022         David Sommerseth <davids@openvpn.net>
//
//  This program is free software: you can redistribute it and/or modify
//  it under the terms of the GNU Affero General Public License as
//  published by the Free Software Foundation, version 3 of the
//  License.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU Affero General Public License for more details.
//
//  You should have received a copy of the GNU Affero General Public License
//  along with this program.  If not, see <https://www.gnu.org/licenses/>.
//

/**
 * @file   service-configfile.hpp
 *
 * @brief  Definition of the elements used in the openvpn3-service-logger
 *         configuration file
 */

#pragma once

#include <memory>
#include <string>
#include "common/configfileparser.hpp"

using namespace Configuration;


class LogServiceConfigFile : public virtual Configuration::File
{
  public:
    typedef std::shared_ptr<Configuration::File> Ptr;

    LogServiceConfigFile()
        : Configuration::File("")
    {
    }

    LogServiceConfigFile(const std::string &statedir)
        : Configuration::File(statedir + "/" + "log-service.json")
    {
    }


  protected:
    Configuration::OptionMap ConfigureMapping()
    {
        return {
            // clang-format off
            OptionMapEntry{"journald", "journald",
                           "log_method_group",
                           "Use systemd-journald",
                           OptionValueType::Present},
            OptionMapEntry{"syslog", "syslog",
                           "log_method_group",
                           "Use syslog",
                           OptionValueType::Present},
            OptionMapEntry{"syslog-facility", "syslog_facility",
                           "Syslog facility",
                           OptionValueType::String},
            OptionMapEntry{"log-file", "log_file",
                           "log_method_group",
                           "Log file",
                           OptionValueType::String},
            OptionMapEntry{"colour", "log_file_colour",
                           "Colour log lines in log file",
                           OptionValueType::Present},
            OptionMapEntry{"log-level", "log_level",
                           "Log level",
                           OptionValueType::Int},
            OptionMapEntry{"service-log-dbus-details", "log_dbus_details",
                           "Add D-Bus details in log file/syslog",
                           OptionValueType::Present},
            OptionMapEntry{"timestamp", "timestamp",
                           "Add timestamp log file",
                           OptionValueType::Present},
            OptionMapEntry{"no-logtag-prefix", "no_logtag_prefix",
                           "Disable LogTag prefixes (systemd-journald)",
                           OptionValueType::Present},
            OptionMapEntry{"idle-exit", "idle_exit",
                           "Idle exit timer (minutes)", OptionValueType::Int},
            // clang-format on
        };
    }
};
