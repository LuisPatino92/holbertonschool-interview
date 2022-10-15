#!/usr/bin/python3
""" Module docstring """


def validUTF8(data):
    """
    Method docstring
    """
    
    n_by = 0
    m_f = 1 << 7
    m_s = 1 << 6

    for chunk in data:
        m_n_by = 1 << 7
        if n_by == 0:
            while m_n_by & chunk:
                n_by += 1
                m_n_by = m_n_by >> 1

            if n_by == 0:
                continue

            if n_by == 1 or n_by > 4:
                return False

        else:
            if not (chunk & m_f and not (chunk & m_s)):
                    return False

        n_by -= 1

    if n_by == 0:
        return True

    return False
