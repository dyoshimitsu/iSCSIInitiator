/*!
 * @author		Nareg Sinenian
 * @file		iSCSIPropertyList.h
 * @version		1.0
 * @copyright	(c) 2013-2015 Nareg Sinenian. All rights reserved.
 * @brief		Provides user-space library functions to read and write
 *              daemon configuration property list
 */

#ifndef __ISCSI_PROPERTY_LIST_H__
#define __ISCSI_PROPERTY_LIST_H__

#include <CoreFoundation/CoreFoundation.h>
#include <errno.h>

#include "iSCSITypes.h"


/*! Copies the initiator name from the property list into a CFString object.
 *  @return the initiator name. */
CFStringRef iSCSIPLCopyInitiatorName();

/*! Sets the initiator name in the property list.
 *  @param initiatorName the initiator name to set. */
void iSCSIPLSetInitiatorName(CFStringRef initiatorName);

/*! Copies the initiator alias from the property list into a CFString object.
 *  @return the initiator alias. */
CFStringRef iSCSIPLCopyInitiatorAlias();

/*! Sets the initiator alias in the property list.
 *  @param initiatorAlias the initiator alias to set. */
void iSCSIPLSetInitiatorAlias(CFStringRef initiatorAlias);

/*! Copies the session configuration from the property list into an object.
 *  @param targetName the name of the target.
 *  @return a session configuration object. */
iSCSISessionConfigRef iSCSIPLCopySessionConfig(CFStringRef targetName);

/*! Sets the session configuration for a particular target.
 *  @param targetName the name of the target to set.
 *  @param sessCfg the session configuration object. */
void iSCSIPLSetSessionConfig(CFStringRef targetName,iSCSISessionConfigRef sessCfg);

/*! Copies a portal object for a particular portal for the specified target.
 *  @param targetName the target name.
 *  @param poralName the portal name (IPv4, IPv6 or DNS name).
 *  @return portal the portal object to set. */
iSCSIPortalRef iSCSIPLCopyPortal(CFStringRef targetName,CFStringRef portalName);

/*! Sets a portal object for a particular portal for the specified target.
 *  @param targetName the target name.
 *  @param portal the portal object to set. */
void iSCSIPLSetPortal(CFStringRef targetName,iSCSIPortalRef portal);

/*! Copies a connection configuration object associated with a particular
 *  portal for the specified target.
 *  @param targetName the target name.
 *  @param poralName the portal name (IPv4, IPv6 or DNS name).
 *  @return the connection configuration object to copy. */
iSCSIConnectionConfigRef iSCSIPLCopyConnectionCfg(CFStringRef targetName,
                                                  CFStringRef portalName);

/*! Sets a connection configuration object associated with a particualr portal
 *  for the specified target.
 *  @param targetName the target name.
 *  @param poralName the portal name (IPv4, IPv6 or DNS name).
 *  @param connCfg the connection configuration object to set. */
void iSCSIPLSetConnectionCfg(CFStringRef targetName,
                             CFStringRef portalName,
                             iSCSIConnectionConfigRef connCfg);

/*! Copies an authentication object associated with a particular
 *  portal for the specified target.
 *  @param targetName the target name.
 *  @param portalName the portal name (IPv4, IPv6 or DNS name).
 *  @return the authentication object. */
iSCSIAuthRef iSCSIPLCopyAuthentication(CFStringRef targetName,
                                       CFStringRef portalName);

/*! Sets an authentication object associated with a particular portal
 *  for the specified target.
 *  @param targetName the target name.
 *  @param portalName the portal name (IPv4, IPv6 or DNS name).
 *  @param auth the connection configuration object to set. */
void iSCSIPLSetAuthentication(CFStringRef targetName,
                              CFStringRef portalName,
                              iSCSIAuthRef auth);

void iSCSIPLSynchronize();


#endif
