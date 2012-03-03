/* efi.h - declare variables and functions for EFI support */
/*
 *  GRUB  --  GRand Unified Bootloader
 *  Copyright (C) 2006,2007,2008,2009  Free Software Foundation, Inc.
 *
 *  GRUB is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  GRUB is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with GRUB.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef GRUB_EFI_EFI_HEADER
#define GRUB_EFI_EFI_HEADER	1

#include <grub/types.h>
#include <grub/dl.h>
#include <grub/efi/api.h>

/* Functions.  */
void *EXPORT_FUNC(grub_efi_locate_protocol) (grub_efi_guid_t *protocol,
					     void *registration);
grub_efi_handle_t *
EXPORT_FUNC(grub_efi_locate_handle) (grub_efi_locate_search_type_t search_type,
				     grub_efi_guid_t *protocol,
				     void *search_key,
				     grub_efi_uintn_t *num_handles);
void *EXPORT_FUNC(grub_efi_open_protocol) (grub_efi_handle_t handle,
					   grub_efi_guid_t *protocol,
					   grub_efi_uint32_t attributes);
int EXPORT_FUNC(grub_efi_set_text_mode) (int on);
void EXPORT_FUNC(grub_efi_stall) (grub_efi_uintn_t microseconds);
void *
EXPORT_FUNC(grub_efi_allocate_pages) (grub_efi_physical_address_t address,
				      grub_efi_uintn_t pages);
void EXPORT_FUNC(grub_efi_free_pages) (grub_efi_physical_address_t address,
				       grub_efi_uintn_t pages);
int
EXPORT_FUNC(grub_efi_get_memory_map) (grub_efi_uintn_t *memory_map_size,
				      grub_efi_memory_descriptor_t *memory_map,
				      grub_efi_uintn_t *map_key,
				      grub_efi_uintn_t *descriptor_size,
				      grub_efi_uint32_t *descriptor_version);
grub_efi_loaded_image_t *EXPORT_FUNC(grub_efi_get_loaded_image) (grub_efi_handle_t image_handle);
void EXPORT_FUNC(grub_efi_print_device_path) (grub_efi_device_path_t *dp);
char *EXPORT_FUNC(grub_efi_get_filename) (grub_efi_device_path_t *dp);
grub_efi_device_path_t *
EXPORT_FUNC(grub_efi_get_device_path) (grub_efi_handle_t handle);
grub_err_t EXPORT_FUNC (grub_efi_finish_boot_services) (grub_efi_uintn_t *outbuf_size, void *outbuf,
							grub_efi_uintn_t *map_key,
							grub_efi_uintn_t *efi_desc_size,
							grub_efi_uint32_t *efi_desc_version);
grub_err_t EXPORT_FUNC (grub_efi_set_virtual_address_map) (grub_efi_uintn_t memory_map_size,
							   grub_efi_uintn_t descriptor_size,
							   grub_efi_uint32_t descriptor_version,
							   grub_efi_memory_descriptor_t *virtual_map);
void *EXPORT_FUNC (grub_efi_get_variable) (const char *variable,
					   const grub_efi_guid_t *guid,
					   grub_size_t *datasize_out);
int
EXPORT_FUNC (grub_efi_compare_device_paths) (const grub_efi_device_path_t *dp1,
					     const grub_efi_device_path_t *dp2);

extern void (*EXPORT_VAR(grub_efi_net_config)) (grub_efi_handle_t hnd, 
						char **device,
						char **path);

grub_addr_t grub_efi_modules_addr (void);

void grub_efi_mm_init (void);
void grub_efi_mm_fini (void);
void grub_efi_init (void);
void grub_efi_fini (void);
void grub_efi_set_prefix (void);

/* Variables.  */
extern grub_efi_system_table_t *EXPORT_VAR(grub_efi_system_table);
extern grub_efi_handle_t EXPORT_VAR(grub_efi_image_handle);

extern int EXPORT_VAR(grub_efi_is_finished);

#endif /* ! GRUB_EFI_EFI_HEADER */
