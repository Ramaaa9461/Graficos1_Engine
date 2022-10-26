#pragma once

namespace FACU_RAMI_ENGINE
{

	class IndexBuffer
	{
	private:
		unsigned int m_RendererID;
		unsigned int m_Count;

	public:
		IndexBuffer(const unsigned* data, unsigned int count); //Video: Abstracing OPENGL into Classes - Min: 14.43
		~IndexBuffer();

		void Bind() const;
		void UnBind() const;

		inline unsigned int GetCount() const { return m_Count; }
	};

}